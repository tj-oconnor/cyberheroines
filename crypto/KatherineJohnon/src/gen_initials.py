#!/usr/bin/env python3

import random
import string
from more_itertools import chunked

initials = '\n'.join(
    map(''.join,
        chunked(random.choices(string.ascii_uppercase[:20], k=1000 * 3), 3)))

print(initials)
