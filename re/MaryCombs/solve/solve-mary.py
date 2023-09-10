import angr
import claripy
import sys
from pwn import *
from ctypes import c_longlong as ll

logging.getLogger('angr').setLevel(logging.WARNING)
logging.getLogger('pwnlib').setLevel(logging.INFO)

binary = args.BIN
context.terminal = ["tmux", "splitw", "-h"]
e = context.binary = ELF(binary, checksec=False)

gs = '''
continue
'''

def start():
    if args.REMOTE:
       return remote("0.cloud.chals.io",16577)
    else:
        return process(e.path)

p = start()
project = angr.Project(binary)
start_address = 0x401709
initial_state = project.factory.blank_state(
    addr=start_address,
    add_options={angr.options.SYMBOL_FILL_UNCONSTRAINED_MEMORY,
                angr.options.SYMBOL_FILL_UNCONSTRAINED_REGISTERS}
)

def solve(t):
    p.recvuntil(b'Random 1 >>> ')
    random_val1 = int(p.recvline())
    p.recvuntil(b'Random 2 >>> ')
    random_val2 = int(p.recvline())

    password = claripy.BVS('', 64)

    initial_state.regs.rdi = random_val1
    initial_state.regs.rsi = random_val2
    initial_state.regs.rdx = t
    initial_state.regs.rcx = password

    simulation = project.factory.simgr(initial_state)
    simulation.explore(find=0x40172e, avoid=0x401715)

    if simulation.found:
        solution_state = simulation.found[0]
        solution = solution_state.solver.eval(password)
        p.sendline(str(ll(solution).value).encode())
        info('Sent solution for iteration: %i' %t)
        log.info('r1=%i,r2=%i,t=%i,p=%i' %(random_val1,random_val2,t,ll(solution).value))
    else:
        raise Exception('Could not solve solution')

for i in range(40):
   p.recvline()
for i in range(1, 100):
    solve(i)
p.interactive()
