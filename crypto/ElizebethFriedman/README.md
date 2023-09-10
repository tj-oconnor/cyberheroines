# Elizabeth Friedman

## Prompt

[Elizebeth Smith Friedman](https://en.wikipedia.org/wiki/Elizebeth_Smith_Friedman) (August 26, 1892 – October 31, 1980) was an American cryptanalyst and author who deciphered enemy codes in both World Wars and helped to solve international smuggling cases during Prohibition. Over the course of her career, she worked for the United States Treasury, Coast Guard, Navy and Army, and the International Monetary Fund.[3] She has been called "America's first female cryptanalyst". - [Wikipedia Source](https://en.wikipedia.org/wiki/Elizebeth_Smith_Friedman)

Chal: Return the flag from this encrypted image to Americas [first female cryptanalyst](https://www.youtube.com/watch?v=VzzAnvsIOnc)

## Solution

Flag has been encoded with AES-ECB. Just copy back the header and the flag will still be visible.

```python
with open('flag_example.bmp', 'rb') as png_header:
    header_bytes = png_header.read(100)

with open('flag.enc', 'rb') as encrypted_file:
    encrypted_bytes = encrypted_file.read()

with open('flag-recovered.bmp', 'wb') as output_file:
    output_file.write(header_bytes) # header
    output_file.write(encrypted_bytes[8:]) # 9th byte on to end
```

Alternatively, you could use ``dd`` to copy the 100 header bytes

```
dd if=flag.bmp bs=1 count=100 of=flag.enc conv=notrunc
```
