#ifndef COMPONENT_H
#define COMPONENT_H

#include "Messages.h"

using namespace Entities::Messages;

namespace Entities{

  class Entity;

  class Component{
    Entity* parent;
  public:
    Entity* getParent()const {return this->parent;}
    void setParent(Entity* new_parent) {this->parent = new_parent;}
    virtual void receive(message msg)=0;
    virtual void update()=0;
  };

}
#endif
