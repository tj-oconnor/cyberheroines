from pwn import *


def is_prime(num):
	if num <= 1:
		return False
	if num <= 3:
		return True
	if num % 2 == 0 or num % 3 == 0:
		return False
	i = 5
	while i * i <= num:
		if num % i == 0 or num % (i + 2) == 0:
			return False
		i += 6
	return True;


def get_prime_func(start):
	while True:
		if is_prime(start) and start % 4 == 3:
			return start
		start += 1


def bbs(p, q, s):
	N = p * q
	x = (s * s) % N
	result = 0
	for i in range(63):
		x = (x * x) % N
		result |= (x & 1) << i
	return result


def main():
	io = process("./bbs")
	io.sendline(b'y')
	io.recvuntil(b'seed: ')
	seed = int(io.recvline().strip())
	original_min = seed // 1337
	p = get_prime_func(original_min)
	q = get_prime_func(p + 1)
	rand_num = bbs(p, q, seed)
	io.sendline(b'%i' %(rand_num))
	io.interactive()


#######################################

if __name__ == "__main__":
	main()
