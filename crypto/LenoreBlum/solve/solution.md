# Blum Blum Shub

This challenge implements the Blum Blum Shub algorithm, which is a cryptographic algorithm used to generate pseudo-random bit sequences.
Through the name of this challenge, the use of this algorithm can be inferred, but it can also be reversed out. Similarly, the functions
used to generate random p, q, and s values (which are used for the random number generation) also must be reversed out to understand how
the problem works. 

The program asks you to play a game (and you say yes, because games are fun). If (or when) you say yes, you are given a "seed" number and
asked to guess the next random number. When looking at the binary you can determine that the program generates three values, one of which
is given to you and is called the "seed". It can be inferred through the use of bbs that the other two numbers are p and q. By looking at
the functions which generate these numbers, it can be seen that the p and q are generated according to the rules set for the algorithm
(they must be congruent to 3 mod 4) however the seed is not. In fact, the rand() value the p and q are based off is used to get the seed
value, which ends up just being the random value multiplied by 1337. We also find that the random number is a 64 bit integer that the
program gets from a random bit sequence using bbs.

From this, there are two approaches one could take. The first is to simply rewrite the functionality for generating the random value with
values pulled from the remote service. The other approach is to make a patched version of the binary with the neccessary values after
getting them from the remote service.

The author solution (aka my solution) implements the former in the form of a python script. It interacts with the remote service, grabs
the random seed, and uses that to get both the p and q, and then to calculate the random value the remote will generate.
