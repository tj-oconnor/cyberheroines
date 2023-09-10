#!/bin/bash

docker run -it --rm -v $PWD/flag.txt:/rocket/flag.txt:ro rocket
