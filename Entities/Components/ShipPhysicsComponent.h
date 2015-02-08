#ifndef SHIP_PHYSICS_COMPONENT_H
#define SHIP_PHYSICS_COMPONENT_H

#include "../Component.h"

#define SHIP_SPEED 0.5
#define SHIP_FRICTION 0.95

using namespace Entities::Messages;

namespace Entities{
  namespace Components{

    class ShipPhysicsComponent : public Component{
      double xspeed, yspeed;
      bool rightPressed, leftPressed;
    public:
      void init(){xspeed = yspeed = rightPressed = leftPressed = 0;}
      virtual void update();
      virtual void receive(message msg);
    };

  }
}

#endif
