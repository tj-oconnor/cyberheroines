
from Crypto.PublicKey import RSA
import binascii

# Generate RSA key pair with a specific public exponent (e)
key = RSA.generate(4096, e=5)

# Message to encrypt
msg = "chctf{d3516n3d_4c0rn_m1cr0_c0mpu73r}"

# Convert the message to bytes and then to an integer
m = int.from_bytes(msg.encode(), byteorder='big')

# Encrypt the message using the public key
c = pow(m, key.e, key.n)

# Write n, e, and c to a file
with open("babyrsa.txt", "w") as f:
    f.write("n = {}\n".format(key.n))
    f.write("e = {}\n".format(key.e))
    f.write("c = {}\n".format(c))
