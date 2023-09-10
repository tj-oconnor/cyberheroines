FROM ubuntu:22.04

RUN apt-get update -y && \
    apt-get install -qq \
    xinetd \
    python3 \
    python3-pip \
    git \
    gdb \
    && apt-get clean

RUN python3 -m pip install --upgrade pip && \
    python3 -m pip install pwntools && \
    git clone https://github.com/pwndbg/pwndbg.git /pwndbg && \
    cd /pwndbg && \
    ./setup.sh

copy chal.bin /chal
run chmod 755 /chal
copy flag.txt /
copy service.conf /service.conf
copy wrapper /wrapper
copy banner_fail /
run chmod +x /wrapper
EXPOSE 31337/TCP

cmd ["/usr/sbin/xinetd", "-filelog", "-", "-dontfork", "-f", "/service.conf"]
