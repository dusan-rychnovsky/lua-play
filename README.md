Usage:
- docker build -t play .
- docker run -it --rm play test.lua

Notes:
- Fails with "ALSA lib seq_hw.c:466:(snd_seq_hw_open) open /dev/snd/seq failed: No such file or directory".
(I didn't find a way to allow the linux-based docker container running on a windows host to access sound card.)
