#include "BulletPhysicsComponent.h"
#include "../Entity.h"

void Entities::Components::BulletPhysicsComponent::
update(){
  Entity* parent = getParent();
  yspeed -= BULLET_SPEED;
  parent->y += yspeed;
  if(parent->y-parent->h < 0) delete parent;
}
