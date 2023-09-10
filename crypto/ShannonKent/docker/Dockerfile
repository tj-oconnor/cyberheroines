FROM python:3.8-slim

RUN apt-get update -y && apt-get -y install socat

RUN pip install pwntools
WORKDIR /app
COPY lock.py .
COPY flag.txt .

EXPOSE 31337/TCP

CMD ["socat", "TCP-LISTEN:31337,fork,reuseaddr", "EXEC:python3 /app/lock.py"]
