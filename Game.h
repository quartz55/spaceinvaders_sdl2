#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <vector>

#include "Globals.h"
#include "World.h"

namespace Entities{
  class Entity;
}

class Game{
  SDL_Window* game_window;
  SDL_Renderer* game_renderer;
  SDL_Event e;
  bool done;

  World game_world;
  
  void handleInput();
  void update();
  void draw();
public:
  bool init();
  void loop();
  void exit();
};

#endif
