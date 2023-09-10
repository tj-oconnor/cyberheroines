# ===================== stage 0 ===================== 
from ubuntu:22.04 as build

run apt update && apt upgrade -y && apt install -y \
    clang \
    make

workdir /root/
copy ./src/ ./src/
copy Makefile .

run make CC=clang build/mainframe

# ===================== stage1 ===================== 

from ubuntu:22.04

run apt update && apt upgrade -y && apt install -y \
    socat \
    python3

run useradd -ms /bin/bash user
workdir /home/user

copy --from=build /root/build/mainframe .
copy --from=build /root/src/punchcard.py .
copy ./scripts/socat_start.sh .

run chmod 755 mainframe punchcard.py socat_start.sh

user user
entrypoint /home/user/socat_start.sh
