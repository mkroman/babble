#include <iostream>

#include "EngineManager.h"
#include "Constants.h"

EngineManager::EngineManager() : running(true), surface(NULL) {
  // …
}

EngineManager::~EngineManager() {
  // …
}

bool EngineManager::Startup() {
  int x = 0, y = 0, dx = 1, dy = 1;

  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    return false;

  if ((surface = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, BITS_PER_PIXEL, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_ANYFORMAT)) == NULL)
    return false;

  while (running) {
    SDL_Event sdlEvent;

    while (SDL_PollEvent(&sdlEvent)) {
      if (sdlEvent.type == SDL_QUIT) {
        std::cout << "Babble is shutting down ..." << std::endl;
        running = false;
      }
    }

    SDL_Rect clearRect;
    clearRect.x = 0;
    clearRect.y = 0;
    clearRect.h = SCREEN_HEIGHT;
    clearRect.w = SCREEN_WIDTH;

    SDL_Rect testRect;

    testRect.x = x;
    testRect.y = y;
    testRect.w = 500;
    testRect.h = 300;

    if (x > SCREEN_WIDTH - testRect.w || x < 0)
      dx = -dx;
    if (y > SCREEN_HEIGHT - testRect.h || y < 0)
      dy = -dy;

    x += dx;
    y += dy;

    SDL_FillRect(surface, &clearRect, 0);
    SDL_FillRect(surface, &testRect, 666666);

    SDL_Flip(surface);
  }

  return true;
}
