#include "World.h"
#include "Entities/Entity.h"

void World
::update(){
  player->update();
  for(unsigned int i = 0; i < bullets.size(); i++)
    bullets[i]->update();

  for(unsigned int i = 0; i < asteroids.size(); i++)
    asteroids[i]->update();
}

void World
::draw(SDL_Renderer* renderer){
  player->draw(renderer);
  for(unsigned int i = 0; i < bullets.size(); i++)
    bullets[i]->draw(renderer);

  for(unsigned int i = 0; i < asteroids.size(); i++)
    asteroids[i]->draw(renderer);
}

void World
::setPlayer(Entities::Entity* new_player){ this->player = new_player;}
