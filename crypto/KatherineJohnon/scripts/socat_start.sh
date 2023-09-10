#!/bin/bash

PORT=3007

socat -d -d \
    tcp-listen:${PORT},fork,reuseaddr \
    system:"python3 ./src/service.py"
