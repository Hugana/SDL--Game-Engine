#include "Game.h"
#include <GameObject.h>
#include <TileMap.h>
#include "Manager.h"
#include "PositionComponent.h"
#include "SpriteComponent.h"
#include "Vector2D.h"
#include "AnimatedSprite.h"



TileMap* level;
SDL_Rect srcR, destR;

Manager manager;

SDL_Renderer* Game::renderer = nullptr;

Game::Game() // Initialize texture to nullptr
{

}

Game::~Game()
{

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen){
    Uint32 flags = 0;

    if(fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        std::cout << "Subsystem Initialised... \n";
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

        if(window){
            std::cout << "Window created! \n";
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer){
            SDL_SetRenderDrawColor(renderer, 10, 10, 10, 0);
            std::cout << "Renderer created! \n";
        }

        isRunning = true;

        level = new TileMap();
        Entity& player = manager.createEntity();
        player.addComponent<PositionComponent>(Vector2D(0,0));
        player.addComponent<AnimatedSprite>("assets/Characters/ElfEnchanterIdleSide.png", 0, 0, 16, 16, 4, static_cast<Uint32>(4));

        Entity& enemy = manager.createEntity();
        enemy.addComponent<PositionComponent>(Vector2D(32,0));
        enemy.addComponent<AnimatedSprite>("assets/Characters/GoblinFighter.png", 0, 0, 16, 16, 4, static_cast<Uint32>(3));


    } else {
        isRunning = false;
    }
}

void Game::handleEvents(){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type){
        case SDL_QUIT:
            isRunning = false;
            break;

        default:
            break;

    }
}

void Game::update(){
    manager.refresh();
    manager.update();

}

void Game::render(){
    SDL_RenderClear(renderer);
    level->DrawMap();
    manager.draw();
    SDL_RenderPresent(renderer);
}

void Game::clean(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    std::cout << "Game cleaned \n";
}

bool Game::running(){
    return isRunning;
}
