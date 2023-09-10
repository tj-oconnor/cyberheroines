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