FROM node:14

RUN apt-get update && \
    apt-get install -y dnsutils

WORKDIR /app
COPY nodejs/package*.json ./
COPY flag.txt ./
RUN npm install
COPY nodejs/ ./
EXPOSE 3000

CMD ["node", "code7.js"]

