#include <iostream>
#include "RtMidi.h"

extern "C"
{
  #include "lua.h"
  #include "lauxlib.h"
  #include "lualib.h"
}

static RtMidiOut midi;

int midi_send(lua_State* L)
{
  double status = lua_tonumber(L, -3);
  double data1 = lua_tonumber(L, -2);
  double data2 = lua_tonumber(L, -1);

  std::cout << "status: " << status << std::endl;
  std::cout << "data1: " << data1 << std::endl;
  std::cout << "data2: " << data2 << std::endl;

  std::vector<unsigned char> message(3);
  message[0] = static_cast<unsigned char>(status);
  message[1] = static_cast<unsigned char>(data1);
  message[2] = static_cast<unsigned char>(data2);
  
  midi.sendMessage(&message);

  return 0;
}

int main(int argc, const char** argv) {
  if (argc < 2) {
    std::cout << "Missing mandatory cmdline argument: <lua-script>" << std::endl;
    return -1;
  }
  std::cout << "Going to play: " << argv[1] << std::endl;

  unsigned int ports = midi.getPortCount();
  if (ports < 1) {
    std::cout << "No midi ports available." << std::endl;
    return -1;
  }
  midi.openPort(0);

  lua_State* L = luaL_newstate();
  luaL_openlibs(L);

  lua_pushcfunction(L, midi_send);
  lua_setglobal(L, "midi_send");

  luaL_dofile(L, argv[1]);
  
  lua_close(L);
  return 0;
}
