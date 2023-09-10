from binascii import unhexlify
from gzip import decompress
from struct import pack
from datetime import datetime
from zipfile import ZipFile
from io import BytesIO
from pwn import xor

# round 4
timestamp = '2023-09-04 11:58:10'
round4_data = b'504b0304140000000800455f2457501c035b3c0000003700000008000000646174612e62696e013700c8ffabd664c8f6617e62630fc76ae616c6d8a3c6e98b0a34fbbbc27f99b00ab9188471de731a39c487fbc12485713aa58b71cf6f417f6cc8a4504b01021403140000000800455f2457501c035b3c00000037000000080000000000000000000000800100000000646174612e62696e504b0506000000000100010036000000620000000000'

# round 3
data_stream = BytesIO(unhexlify(round4_data))
with ZipFile(data_stream, 'r') as zip_file:
    round3_data = zip_file.read(zip_file.namelist()[0])

# round 2
ts = datetime.strptime(str(timestamp), "%Y-%m-%d %H:%M:%S")
tsec = int(ts.timestamp())
ts_bytes = pack('<I', tsec)
gzip_header = b'\x1f\x8b\x08\x00\x00\x00\x00\x00\x02\xff'
reconstructed_header = gzip_header[:4] + ts_bytes[:4] + gzip_header[8:]
round3_key = xor(reconstructed_header,round3_data[0:10])
round2_data = xor(round3_data,round3_key)

# round 1
round1_data = decompress(round2_data)
round1_key = xor(round1_data[0:6],b'chctf{')

# flag
flag = xor(round1_data,round1_key)
print(flag)
