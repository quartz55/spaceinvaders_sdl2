#include "Game.h"

#include <time.h>
#include <iostream>

#include "Entities/Entity.h"
#include "Entities/Messages.h"
#include "Entities/Components/ShipPhysicsComponent.h"

using namespace Entities::Messages;

bool Game
::init(){
  /* SDL stuff
   *   Make window and renderer */
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return false;
	}
  else{
    game_window = SDL_CreateWindow("Space Shooter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    game_renderer = SDL_CreateRenderer(game_window, -1, SDL_RENDERER_ACCELERATED);
  }

  /* Random seed */
  srand(time(NULL));

  /* Create player */
  Entities::Entity* player = new Entities::Entity();
  player->w = 60; player->h = 15;
  player->x = (SCREEN_WIDTH/2-player->w);
  player->y = (SCREEN_HEIGHT-player->h-10);
  player->addComponent(new Entities::Components::ShipPhysicsComponent());

  game_world.setPlayer(player);

  done = false;

  return true;
}

void Game
::loop(){
  while(!done){
    handleInput();
    update();
    draw();
    SDL_Delay(1000/60);
  }
}

void Game
::handleInput(){
  while(SDL_PollEvent(&e)){
    switch(e.type){
    case SDL_QUIT:
      done = true; break;
    case SDL_KEYDOWN:
      if(e.key.keysym.sym == SDLK_ESCAPE) done = true;
      if(e.key.keysym.sym == SDLK_d) game_world.getPlayer()->send(RIGHT_PRESSED);
      if(e.key.keysym.sym == SDLK_a) game_world.getPlayer()->send(LEFT_PRESSED);
      break;
    case SDL_KEYUP:
      if(e.key.keysym.sym == SDLK_d) game_world.getPlayer()->send(RIGHT_RELEASED);
      if(e.key.keysym.sym == SDLK_a) game_world.getPlayer()->send(LEFT_RELEASED);
      break;
    }
  }
}

void Game
::update(){
  game_world.update();
}

void Game
::draw(){
  /* Clean renderer */
  SDL_SetRenderDrawColor(game_renderer, 32, 32, 32, 255);
  SDL_RenderClear(game_renderer);

  /* Draw Entities */
  game_world.draw(game_renderer);

  /* Draw renderer */
  SDL_RenderPresent(game_renderer);
}
