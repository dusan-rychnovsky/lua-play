#include <iostream>

extern "C"
{
  #include "lua.h"
  #include "lauxlib.h"
  #include "lualib.h"
}

int main(int argc, const char** argv) {
  if (argc < 2) {
    std::cout << "Missing mandatory cmdline argument: <lua-script>" << std::endl;
    return -1;
  }
  
  std::cout << "Going to play: " << argv[1] << std::endl;

  lua_State* L = luaL_newstate();
  luaL_openlibs(L);
  luaL_dofile(L, argv[1]);
  lua_close(L);
  return 0;
}
