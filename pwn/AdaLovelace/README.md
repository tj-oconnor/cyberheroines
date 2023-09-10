# Building

## Challenge files

To build the challenge, run `make release`.
The participant's file is now located in `./build/punchcard.tar.xz`

## Hosting the service

To build the hosting docker image, run `docker build -t punchcard .`

When you run the container with `./scripts/docker_start.sh` script,
you can then get the container's IP by saying
`docker ps` and `docker inspect <container id>`.

Then connect to the service like in: `nc <ip> 1075`

Once finished, you'll need to ensure the container can run with the `personality` syscall
which is not in the default seccomp profile. 
An example `docker_run.sh` script is available in `./scripts/` 
and an example profile in `./profile.json`.

# Hints

- It's using `Ubuntu GLIBC 2.35-0ubuntu3.1`
- Use the tcache

# Solution

The solutions in `./tests` may need to be modified depending on your hosting system.

Xor the printed values and substitue them, little endian, in the solution's first
update command.

```
A8A8D0D1F1<put the value here>A8A8F3666c6167
```

Then put this into the punch cards as in `./tests/vuln.bin` and you're done.
