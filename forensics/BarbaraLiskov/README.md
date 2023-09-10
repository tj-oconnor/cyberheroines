# Barbara Liskov

## Prompt

Barbara Liskov (born November 7, 1939 as Barbara Jane Huberman) is an American computer scientist who has made pioneering contributions to programming languages and distributed computing. Her notable work includes the development of the Liskov substitution principle which describes the fundamental nature of data abstraction, and is used in type theory (see subtyping) and in object-oriented programming (see inheritance). Her work was recognized with the 2008 Turing Award, the highest distinction in computer science. - [Wikipedia Entry](https://en.wikipedia.org/wiki/Barbara_Liskov)

Chal: Return the flag back to the [2008 Turing Award Winner](https://www.youtube.com/watch?v=_jTc1BTFdIo). 


## Solution

The problem is a Python3 script 

```python
import base64

# I-Won-A-Turing-Award
def secret_code():
    obfuscated_string = '492d576f6e2d412d547572696e672d4177617264'
    return bytes.fromhex(obfuscated_string).decode('utf-8')

def validate_input(user_input):
    return user_input == secret_code()

# chctf{u_n3v3r_n33d_0pt1m4l_p3rf0rm4nc3,_u_n33d_g00d-3n0ugh_p3rf0rm4nc3}
def print_the_flag():
    encoded_string = 'Y2hjdGZ7dV9uM3Yzcl9uMzNkXzBwdDFtNGxfcDNyZjBybTRuYzMsX3VfbjMzZF9nMDBkLTNuMHVnaF9wM3JmMHJtNG5jM30='
    bytes = base64.b64decode(encoded_string)
    data = bytes.decode('utf-8')
    print(data)


def main():
    user_input = input('Enter the digital code >>> ')
    if validate_input(user_input):
        print_the_flag()
    else:
        print('<<< Incorrect code.')

if __name__ == '__main__':
    main()
 ```

 However the program has been compiled using the command ``python3 -m py_compile BarbaraLiskov.py``

 Since Python 3.11.4 has been used to build it, it will break most tools like decompyle3 or uncompyle6. 
 You can simply run strings against the compiled script, spot the base64 encoded text and issue the 
 command: ``echo Y2hjdGZ7dV9uM3Yzcl9uMzNkXzBwdDFtNGxfcDNyZjBybTRuYzMsX3VfbjMzZF9nMDBkLTNuMHVnaF9wM3JmMHJtNG5jM30= | base64 -d``
to return the flag ``chctf{u_n3v3r_n33d_0pt1m4l_p3rf0rm4nc3,_u_n33d_g00d-3n0ugh_p3rf0rm4nc3}``  