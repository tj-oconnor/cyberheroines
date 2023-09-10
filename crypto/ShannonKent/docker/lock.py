from random import randint
from zipfile import ZipFile, ZIP_DEFLATED
from gzip import compress
from binascii import hexlify
from pwn import xor, text
from io import BytesIO
from struct import unpack,pack
from datetime import datetime

def random_key(length):
    return bytes(randint(0, 255) for _ in range(length))

def compress_with_zip(data):
    compressed_data = BytesIO()
    with ZipFile(compressed_data, 'w', compression=ZIP_DEFLATED) as zip_file:zip_file.writestr('data.bin', data)
    return compressed_data.getvalue()

def compress_with_gzip(data):
    compressed_data = compress(data)
    return compressed_data

def get_ts(data):
    timestamp = data[4:8]
    timestamp_seconds = unpack('<I', timestamp)[0]
    timestamp_datetime = datetime.fromtimestamp(timestamp_seconds)
    return timestamp_datetime

def pink_text(text):
    return f"\033[95m{text}\033[0m"  # ANSI escape code for pink

def tie_a_knot():
    with open('flag.txt', 'rb') as file:flag = file.read()

    round1_key = random_key(6)
    round1_data = xor(flag, round1_key)   
    round2_data = compress_with_gzip(round1_data)
    round3_key = random_key(10)
    round3_data = xor(round2_data, round3_key)
    round4_data = compress_with_zip(round3_data)

    print(pink_text(pink_text("<<< Tying a Secure Knot Around the File")))
    ts = "Started: %s" %get_ts(round2_data)
    print(pink_text('<<<'),end=' ')
    print(ts)
    print(pink_text("--------------------------------------------------------------------------------"))
    print(pink_text("<<< XORing flag with random 6 byte key"))
    print(pink_text("<<< GZIPing result (with gzip.compress with max compression)"))
    print(pink_text("<<< XORing result with random 10 byte key"))
    print(pink_text("<<< ZIPping result (with zipfile.ZipFile compression=ZIP_DEFLATED)"))
    print('<<< Flag is secure: %s' %hexlify(round4_data).decode())

def logo():
    print(pink_text("--------------------------------------------------------------------------------"))
    print(pink_text("                          Flag Storage Safe v0.1337                             "))
    print(pink_text("--------------------------------------------------------------------------------"))  
    print(pink_text("                                                                                "))
    print(pink_text("                                   WWWWWWWWWW                                   "))
    print(pink_text("                              WNXK000000000000KXNW                              "))
    print(pink_text("                           WNK0O0KKXNNWWWWNNXKK000KNW                           "))
    print(pink_text("                         WX0O0XWW   WWWWWWWW   WWX0O0XW                         "))
    print(pink_text("                       WXOOKNW WWXK0000000000KXW  WNKOOXW                       "))
    print(pink_text("                      WKk0NW WNKOO0KXNWWWWNXK0OOKNW WN0kKW                      "))
    print(pink_text("                     W0kKW  NKO0XW            WX0OKN  WKk0W                     "))
    print(pink_text("                    WKkKW  NOOXW                WXOON  WKkKW                    "))
    print(pink_text("                    NOON  W0kXW                  WXk0W  NOON                    "))
    print(pink_text("                   WXk0W  Xk0W                    W0kX  W0kX                    "))
    print(pink_text("                   WKkKW WKkKW                    WKkKW WKkKW                   "))
    print(pink_text("                   WKkKW WKkKW                    WKkKW WKkKW                   "))
    print(pink_text("                   WKkKW WKkKW                    WKkKW WKkKW                   "))
    print(pink_text("                   WKkKW WKkKW                    WKkKW WKkKW                   "))
    print(pink_text("                 WNXOkKW WKkOKKKKKKKKKKKKKKKKKKKKKKOkKW WKkOXNW                 "))
    print(pink_text("               WX0O00KN   NKKKKKKKKKKKKKKKKKKKKKKKKKKN   NK00O0XW               "))
    print(pink_text("              W0kKNW  WWWWWWNNNNNNWWWWWWWWWWWWNNNNNNWWWWWW  WNKk0W              "))
    print(pink_text("              Xk0W  NKOkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkOKN  W0kX              "))
    print(pink_text("             WKkKWWNOddddddddddddddddddddddddddddddddddddddONWWKkKW             "))
    print(pink_text("             WKkKWWXkddddddddddddddddddddddddddddddddddddddkX WKkKW             "))
    print(pink_text("             WKkKW XkddddddddddddddxO000000OxddddddddddddddkX WKkKW             "))
    print(pink_text("             WKkKW Xkddddddddddddx0XW      WX0xddddddddddddkX WKkKW             "))
    print(pink_text("             WKkKWWXkdddddddddddxKW          WKxdddddddddddkXWWKkKW             "))
    print(pink_text("             WKkKW XkdddddddddddON            NOdddddddddddkXWWKkKW             "))
    print(pink_text("             WKkKW XkdddddddddddkX            XkdddddddddddkXWWKkKW             "))
    print(pink_text("             WKkKW XkdddddddddddxONW        WNOxdddddddddddkXWWKkKW             "))
    print(pink_text("             WKkKW XkdddddddddddddkKW      WKkdddddddddddddkXWWKkKW             "))
    print(pink_text("             WKkKW XkddddddddddddddkXW    WXkddddddddddddddkXWWKkKW             "))
    print(pink_text("             WKkKW XkddddddddddddddkXW    WXkddddddddddddddkXWWKkKW             "))
    print(pink_text("             WKkKW Xkddddddddddddddx0NW  WN0xddddddddddddddkXWWKkKW             "))
    print(pink_text("             WKkKW Xkdddddddddddddddxk0KK0kxdddddddddddddddkXWWKkKW             "))
    print(pink_text("             WKkKW XkddddddddddddddddddddddddddddddddddddddkXWWKkKW             "))
    print(pink_text("             WKkKW NOddddddddddddddddddddddddddddddddddddddONWWKkKW             "))
    print(pink_text("              Xk0WWWNKOkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkOKNW W0kX              "))
    print(pink_text("              W0k0NWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW WWN0k0W              "))
    print(pink_text("               WX0O00KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK00O0XW               "))
    print(pink_text("                 WNXKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKXNW                 "))
    print(pink_text("                                                                                "))
    print(pink_text("--------------------------------------------------------------------------------"))


def main():
    logo()
    tie_a_knot()
    print(pink_text("--------------------------------------------------------------------------------"))


if __name__ == '__main__':
    main()
