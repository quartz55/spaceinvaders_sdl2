#ifndef WORLD_H
#define WORLD_H

#include <vector>

class SDL_Renderer;

namespace Entities{
  class Entity;
}

class World{
  std::vector<Entities::Entity*> bullets, asteroids;
  Entities::Entity* player;
public:
  std::vector<Entities::Entity*> getBullets()const {return bullets;}
  std::vector<Entities::Entity*> getAsteroids()const {return asteroids;}
  Entities::Entity* getPlayer()const {return player;}

  void setPlayer(Entities::Entity* new_player);
  void addBullet(Entities::Entity* new_bullet);
  void addAsteroid(Entities::Entity* new_asteroid);
  void removeBullet(Entities::Entity* bullet);
  void removeAsteroid(Entities::Entity* asteroid);
  
  void update();
  void draw(SDL_Renderer* renderer);
};

#endif
