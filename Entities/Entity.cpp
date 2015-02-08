#include "Entity.h"

#include "Component.h"

#include <SDL2/SDL.h>

Entities::Entity
::Entity(){
  x = y = w = h = 0;
}

void Entities::Entity
::update(){
  for(unsigned int i = 0; i < components_.size(); i++){
    components_[i]->update();
  }
}

void Entities::Entity
::draw(SDL_Renderer* renderer){
  SDL_Rect rect = {x,y,w,h};
  SDL_SetRenderDrawColor(renderer, 234, 234, 234, 255);
  SDL_RenderFillRect(renderer, &rect);
}

void Entities::Entity::
addComponent(Component* new_component){
  if(new_component != NULL){
    new_component->setParent(this);
    components_.push_back(new_component);
  }
}

void Entities::Entity::
send(message msg){
  for(unsigned int i = 0; i < components_.size(); i++)
    components_[i]->receive(msg);
}
