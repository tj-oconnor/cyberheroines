import wave
import sys

def embed_image_into_audio(audio_path, image_path, output_audio_path):
    with open(image_path, 'rb') as image_file:
        image_data = image_file.read()
        image_len = len(image_data)

    with wave.open(audio_path, 'rb') as audio_file:
        audio_data = bytearray(audio_file.readframes(audio_file.getnframes()))

    # Embed image size into the first 32 bits
    for i in range(32):
        audio_data[i] = (audio_data[i] & 0xFE) | ((image_len >> i) & 1)

    # Embed image data into audio LSBs
    audio_index = 32
    for byte in image_data:
        for i in range(8):
            audio_data[audio_index] = (audio_data[audio_index] & 0xFE) | ((byte >> i) & 1)
            audio_index += 1

    with wave.open(output_audio_path, 'wb') as output_file:
        output_file.setparams(audio_file.getparams())
        output_file.writeframes(audio_data)

if __name__ == "__main__":
    if len(sys.argv) != 4:
        print("Usage: python embed_image_into_audio.py <audio_path> <image_path> <output_audio_path>")
        sys.exit(1)

    audio_path = sys.argv[1]
    image_path = sys.argv[2]
    output_audio_path = sys.argv[3]

    embed_image_into_audio(audio_path, image_path, output_audio_path)
