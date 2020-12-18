FROM        debian:8.0
ENV         LANG C.UTF-8
RUN         apt-get update -qq && apt-get install -y build-essential patch lua5.2 lua5.2-dev
COPY        ./play.cpp /var/play/
COPY        ./*.lua /var/play
RUN         cd /var/play && g++ -I/usr/include/lua5.2 -L/usr/bin -llua5.2 -o play play.cpp
WORKDIR     /var/play
ENTRYPOINT  ["/var/play/play"]
