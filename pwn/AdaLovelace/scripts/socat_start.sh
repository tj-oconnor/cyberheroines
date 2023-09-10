#!/bin/bash

PORT=1075

socat \
    -d -d \
    tcp-listen:${PORT},fork,reuseaddr \
    system:"python3 ./punchcard.py | ./mainframe",stderr
