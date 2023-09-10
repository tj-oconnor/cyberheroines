# Dorothy Vaughan

## Prompt

[Dorothy Jean Johnson Vaughan](https://en.wikipedia.org/wiki/Dorothy_Vaughan) (September 20, 1910 – November 10, 2008) was an American mathematician and human computer who worked for the National Advisory Committee for Aeronautics (NACA), and NASA, at Langley Research Center in Hampton, Virginia. In 1949, she became acting supervisor of the West Area Computers, the first African-American woman to receive a promotion and supervise a group of staff at the center. - [Wikipedia Entry](https://en.wikipedia.org/wiki/Dorothy_Vaughan)

Chal: We ran this Fortran Software and received the output ``Final Array:bcboe{g4cy:ixa8b|m:8}``. We have no idea what this means but return the flag to the [Human Computer](https://www.youtube.com/watch?v=zMAFPRgsCDM)

## Solution

This challenge was a very simple encryption in a language that made understanding it harder. Reversing the binary and then deciphering the math being done is all that is necessary. The code also ignores the {} and leaves them alone. Odd index add 3 to the ascii in the index, even index add 7 to the ascii in the index:
c  h  c  t  f  {  h  1  d  d  3  n  _  f  1  g  u  r  3  5  }
+7 +3 +7 +7 +3 +7 +7 +3 +7 +7 +3 +7 +7 +3 +7 +7 +3 +7 +7 +3 +7
Then everything is rotated by 18, also ignoring the {}:
bcboe{g4cy:ixa8b|m:8}

To get the orignial flag you only need rotate the value 8 and then subtract the same numbers from the same indexes instead of adding them. Then you will have the flag.
