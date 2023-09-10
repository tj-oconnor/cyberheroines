FROM python:3.8-slim

RUN apt-get update -y && apt-get install sqlite3

WORKDIR /app
COPY webapp/ /app
COPY flag.txt /
RUN pip install --no-cache-dir -r /app/requirements.txt

EXPOSE 5000

USER root

CMD ["python", "/app/app.py"]
