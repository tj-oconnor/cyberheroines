# Anita Borg

## Prompt

[Anita Borg]() (January 17, 1949 – April 6, 2003) was an American computer scientist celebrated for advocating for women’s representation and professional advancement in technology. She founded the Institute for Women and Technology and the Grace Hopper Celebration of Women in Computing. - [Wikipeda Entry](https://en.wikipedia.org/wiki/Anita_Borg)

Chal: Have the vision to solve this binary and learn more about this [visionary](https://www.youtube.com/watch?v=qMfELzvXpBo)

## Solution

Its a ``movcc`` compiled binary. Just ``ltrace`` it and you should see the flag in a ``strncmp``

```
strncmp("AAAAAAAAAAAAAAAAAAAA\n}\320\367chctf{b_"..., "chctf{b_A_V1s10NArY_2}", 22)                                           = -1
```
