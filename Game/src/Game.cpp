#include "Game.h"

SDL_Texture* playerTex;
SDL_Rect srcR, destR;

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
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer created! \n";
        }

        isRunning = true;
    } else {
        isRunning = false;
    }

    SDL_Surface* tmpSurface = IMG_Load("src/assets/ElfEnchanterIdleSide.png");

     if (!tmpSurface) {
        std::cout << "Failed to load image: " << IMG_GetError() << std::endl;
    }

    playerTex = SDL_CreateTextureFromSurface(renderer,tmpSurface);
    SDL_FreeSurface(tmpSurface);
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

    // Game logic goes here
    destR.w = 4 * 16;  // Width on the screen (same as the sprite's width)
    destR.h = 4 * 16;

    srcR.x = 16;                   // Move horizontally based on character index
    srcR.y = 0;                    // All characters are on the same row
    srcR.w = 16;                   // Width of each character sprite
    srcR.h = 16;                   // Height of each character sprite


}

void Game::render(){
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,playerTex, &srcR ,&destR);
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
