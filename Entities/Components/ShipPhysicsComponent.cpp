#include "ShipPhysicsComponent.h"

#include "../../Globals.h"
#include "../Entity.h"

#include <math.h>

void Entities::Components::ShipPhysicsComponent
::receive(message msg){
  switch(msg){
  case RIGHT_PRESSED:
    rightPressed = true; break;
  case RIGHT_RELEASED:
    rightPressed = false; break;
  case LEFT_PRESSED:
    leftPressed = true; break;
  case LEFT_RELEASED:
    leftPressed = false; break;
  }
}

void Entities::Components::ShipPhysicsComponent::
update(){

  /* Check Ship input */
  if(rightPressed) xspeed += SHIP_SPEED;
  else if(leftPressed) xspeed -= SHIP_SPEED;

  Entity* parent = getParent();

  /* Check Ship boundaries */
  if(parent->x + parent->w + xspeed > SCREEN_WIDTH){
    xspeed = 0;
    parent->x = (SCREEN_WIDTH-parent->w);
  }
  else if(parent->x + xspeed < 0){
    xspeed = 0;
    parent->x = 0;
  }

  xspeed *= SHIP_FRICTION;
  if(fabs(xspeed) <= 0.5
     && !rightPressed && !leftPressed) xspeed = 0;

  /* Update Ship Position */
  parent->x += xspeed;
  parent->y += yspeed;
}
