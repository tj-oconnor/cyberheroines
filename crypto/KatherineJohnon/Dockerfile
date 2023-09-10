from python:3.11.5

run apt update && apt install -y \
    socat

run python3 -m pip install more_itertools

workdir /rocket
copy src/service.py ./src/service.py
copy src/gen_initials.py ./src/gen_initials.py
copy scripts/socat_start.sh ./start.sh
copy initials.txt .
copy flag.txt .

EXPOSE 3007/TCP
entrypoint ./start.sh
