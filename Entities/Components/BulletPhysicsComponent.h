#ifndef BULLET_PHYSICS_COMPONENT_H
#define BULLET_PHYSICS_COMPONENT_H

#include "../Component.h"

#define BULLET_SPEED 2

namespace Entities{
  namespace Components{
    class BulletPhysicsComponent : public Component{
      double yspeed;
    public:
      virtual void receive(message msg){}
      virtual void update();
    };
  }
}

#endif
