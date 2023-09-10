import wave
import sys

def extract_image_from_audio(encoded_audio_path, output_image_path):
    with wave.open(encoded_audio_path, 'rb') as audio_file:
        audio_data = bytearray(audio_file.readframes(audio_file.getnframes()))

    # Extract the size of the image from the first 32 bits
    image_len = sum((audio_data[i] & 1) << i for i in range(32))

    image_data = bytearray()
    audio_index = 32

    for _ in range(image_len):
        byte = sum((audio_data[audio_index + i] & 1) << i for i in range(8))
        image_data.append(byte)
        audio_index += 8

    with open(output_image_path, 'wb') as image_file:
        image_file.write(image_data)

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python extract_image_from_audio.py <encoded_audio_path> <output_image_path>")
        sys.exit(1)

    encoded_audio_path = sys.argv[1]
    output_image_path = sys.argv[2]

    extract_image_from_audio(encoded_audio_path, output_image_path)
