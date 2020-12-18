FROM        ubuntu:20.04
ENV         LANG C.UTF-8
ENV         DEBIAN_FRONTEND=noninteractive 
RUN         apt-get update -qq && apt-get install -y build-essential cmake patch lua5.2 lua5.2-dev librtmidi-dev
COPY        ./play.cpp /var/play/
COPY        ./CMakeLists.txt /var/play/
COPY        ./*.lua /var/play
RUN         cd /var/play && cmake . && make
WORKDIR     /var/play
ENTRYPOINT  ["/var/play/play"]
