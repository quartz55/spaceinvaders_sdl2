#ifndef ENTITY_H
#define ENTITY_H

#include <vector>

#include "Messages.h"

#define MAX_COMPONENTS 10

class SDL_Renderer;

using namespace Entities::Messages;

namespace Entities{

  class Component;

  class Entity{
    std::vector<Component*> components_;
  public:
    int x,y;
    int w,h;

    Entity();
    void addComponent(Component* new_component);
    void send(message msg);

    void update();
    void draw(SDL_Renderer* renderer);
  };
}

#endif
