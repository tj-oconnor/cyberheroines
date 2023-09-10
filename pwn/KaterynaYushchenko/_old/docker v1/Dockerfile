FROM kalilinux/kali-rolling:latest

run apt-get -qq update && apt-get install -qq xinetd 

copy chal.bin_patched /chal
run chmod 755 /chal

copy /ld-linux-x86-64.so.2 /
run chmod 755 /ld-linux-x86-64.so.2

copy /libc.so.6 /
run chmod 755 /libc.so.6  

copy flag.txt /

copy service.conf /service.conf
copy wrapper /wrapper
copy banner_fail /

EXPOSE 31337/TCP

cmd ["/usr/sbin/xinetd", "-filelog", "-", "-dontfork", "-f", "/service.conf"]
