cmake_minimum_required (VERSION 2.8)
project (play)
add_executable (play play.cpp)
include_directories(/usr/include/lua5.2 /usr/include/rtmidi/)
target_link_libraries (play lua5.2 /usr/lib/x86_64-linux-gnu/librtmidi.so)
