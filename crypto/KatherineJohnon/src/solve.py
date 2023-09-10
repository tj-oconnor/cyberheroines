#!/usr/bin/env python3

import string
import time
import random
import re
from copy import copy, deepcopy
from bisect import bisect
from collections import defaultdict

import pwn
import numpy as np

letters = string.ascii_uppercase

IP = '0.cloud.chals.io'
PORT = 21838

with open('initials.txt', 'r') as f:
    initials = f.read().strip().split('\n')

feature_calc = [
    lambda x, y, z: f"{x}{y}{z}",
    lambda x, y, z: f"{x}{y}",
    lambda x, y, z: f"{x}{z}",
    lambda x, y, z: f"{y}{z}",
    lambda x, y, z: f"{x}",
    lambda x, y, z: f"{y}",
    lambda x, y, z: f"{z}",
]

features = [set(func(*i) for i in initials) for func in feature_calc]


class Item(str):
    def set_score(self, score):
        self.score = score
        return self

    def get_score(self):
        if not hasattr(self, 'score'):
            self.score = 0
        return self.score

    def copy(self):
        return Item(self).set_score(self.get_score())


class Cache(list):
    pass


class State():
    def __init__(self,
                 key=None,
                 obs=None,
                 idx=0,
                 cache=None,
                 updated=None,
                 parent_score=None):
        self.key = key
        if key is None:
            scrambled = list(letters)
            random.shuffle(scrambled)
            self.key = {a: x for a, x in zip(letters, scrambled)}

        self.obs = []
        if obs is not None:
            self.obs = list(map(Item, obs))

        self.idx = idx

        self.cache = cache
        if cache is None:
            self.cache = defaultdict(Cache)
            for initial in self.obs:
                for letter in initial:
                    self.cache[letter].append(initial)

        if updated is None and self.obs:
            self.score = self.merge_score(self.calc_score(self.obs))
        elif updated and parent_score is not None:
            old = sum(item.get_score() for item in updated)
            new = self.calc_score(updated)
            diff = self.merge_score(new - old)
            self.score = tuple(
                np.array(parent_score, dtype=int) + \
                np.array(diff, dtype=int)
            )
        else:
            self.score = (0, 0, 0)

    def encrypt_one(self, message):
        return ''.join(self.key.get(x, '') for x in message)

    def _encrypt_many(self, messages):
        return map(self.encrypt_one, messages)

    def _score_one(self, message):
        return np.array([
            1 if calc(*message) in feat else 0
            for feat, calc in zip(features, feature_calc)
        ])

    def _score_many(self, messages):
        return sum(map(self._score_one, messages))

    def merge_score(self, split_score):
        t = tuple(split_score)
        return (t[0], sum(t[1:4]), sum(t[4:]))

    def _set_score_one_item(self, item):
        item.set_score(self._score_one(self.encrypt_one(item)))
        return item.score

    def calc_score(self, obs):
        return sum(map(self._set_score_one_item, obs))

    def step(self):
        high = self
        for idx1 in range(len(letters)):
            for idx2 in range(idx1 + 1, len(letters)):
                new_state = self.swap(letters[idx1], letters[idx2])
                high = max(high, new_state)
        return high

    def swap(self, inp1, inp2):
        key = copy(self.key)
        tmp = key[inp1]
        key[inp1] = key[inp2]
        key[inp2] = tmp

        cache = copy(self.cache)
        cache[inp1] = deepcopy(self.cache[inp1])
        cache[inp2] = deepcopy(self.cache[inp2])

        updated = set(cache[inp1] + cache[inp2])

        return State(key,
                     obs=self.obs,
                     idx=self.idx + 1,
                     cache=cache,
                     updated=updated,
                     parent_score=self.score)

    def __lt__(self, other):
        return self.score < other.score

    def __eq__(self, other):
        if isinstance(other, State):
            return self.key == other.key
        return False

    def __repr__(self):
        s = ''.join(self.key[l] for l in letters)
        return f"State(idx={self.idx:02d}, key={s}, score={self.score})"


def get_some_data(io):
    data = io.read(timeout=0)
    print(len(data))
    data = data.decode().split('\n')
    ctr = 0
    while len(data) > 0 and len(data[-1]) != 7:
        item = data.pop()
        if ctr > 0:
            item = item + '\n'
        io.unread(item)
        ctr += 1
    print('\n', end='')
    return [x[:3] for x in data]


DUMMY_STATE = State()


def attempt():
    ct = []
    #r = pwn.process('./src/service.py')
    r = pwn.remote(IP, PORT)

    time.sleep(15)
    ct.extend(get_some_data(r))

    itr = 0
    while itr < 10000:
        new_best = State(obs=ct)
        best = DUMMY_STATE
        while best < new_best:
            best = new_best
            print(len(ct), best)
            new_best = best.step()
            itr += 1
        if best.score[0] >= 200:
            break

    inv_key = {v: k for k, v in best.key.items()}

    data = r.read(1024).decode()
    m = re.search(r'\n(\S{3})\n', data)
    di = m.groups()[0]
    e = ''.join(inv_key[x] for x in f"{di}LAND")
    print(e)
    r.send(e)
    print(r.recvall(timeout=1))


if __name__ == "__main__":
    attempt()
    pass
