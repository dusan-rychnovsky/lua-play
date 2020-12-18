FROM        debian:8.0
ENV         LANG C.UTF-8
RUN         apt-get update -qq && apt-get install -y build-essential cmake patch lua5.2 lua5.2-dev
COPY        ./play.cpp /var/play/
COPY        ./CMakeLists.txt /var/play/
COPY        ./*.lua /var/play
RUN         cd /var/play && cmake . && make
WORKDIR     /var/play
ENTRYPOINT  ["/var/play/play"]
