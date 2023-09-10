#!/bin/bash

docker run \
    -it \
    --rm \
    -v $PWD/flag.txt:/home/user/flag.txt:ro \
    --security-opt seccomp=$PWD/profile.json \
    punchcard \
        sh ./scripts/socat_start.sh
