# SallyRide

## Prompt

[Sally Kristen Ride](https://en.wikipedia.org/wiki/Sally_Ride) (May 26, 1951 – July 23, 2012) was an American astronaut and physicist. Born in Los Angeles, she joined NASA in 1978, and in 1983 became the first American woman and the third woman to fly in space, after cosmonauts Valentina Tereshkova in 1963 and Svetlana Savitskaya in 1982. She was the youngest American astronaut to have flown in space, having done so at the age of 32. - [Wikipedia Entry](https://en.wikipedia.org/wiki/Sally_Ride)

Chal: I asked ChatGPT to build this binary to honor my hero, [the first woman in space](https://www.youtube.com/watch?v=jwu-zSdNiLI), but its broken and I cannot seem to figure out why. Connect to ``0.cloud.chals.io 10568`` and help me return the flag.

## Solution

The program is a C binary compiled with python libraries using `` -I/usr/include/python2.7 -lpython2.7``. As such the ``input()`` function vulnerability is present. You can arbitraily insert code and get it to execute within the namespace. One simple escape is ``eval('__import__("os").system("cat flag.txt")')`` but there are many other options.

The flag is ``chctf{u_cant_B_Wh4t_u_caNT_S33}``



