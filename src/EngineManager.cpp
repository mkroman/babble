#include <iostream>
#include <boost/foreach.hpp>

#include "EngineManager.h"
#include "BaseObject.h"
#include "Constants.h"

EngineManager::EngineManager() : running(true), surface(NULL) {
  // …
}

EngineManager::~EngineManager() {
  // …
}

bool EngineManager::Startup() {
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

    AddBaseObjects();
    RemoveBaseObjects();

    BOOST_FOREACH (BaseObject* object, baseObjects)
      object->EnterFrame(100.0f);

    SDL_Rect clearRect;
    clearRect.x = 0;
    clearRect.y = 0;
    clearRect.h = SCREEN_HEIGHT;
    clearRect.w = SCREEN_WIDTH;

    SDL_FillRect(surface, &clearRect, 0);

    BOOST_FOREACH (BaseObject* object, baseObjects)
      object->Draw(surface);

    SDL_Flip(surface);
  }

  return true;
}

void EngineManager::AddBaseObject(BaseObject* object) {
  addedBaseObjects.push_back(object);
}

void EngineManager::RemoveBaseObject(BaseObject* object) {
  removedBaseObjects.remove(object);
}

void EngineManager::AddBaseObjects() {
  BOOST_FOREACH (BaseObject* object, addedBaseObjects)
    baseObjects.push_back(object);
  addedBaseObjects.clear();
}

void EngineManager::RemoveBaseObjects() {
  BOOST_FOREACH (BaseObject* object, removedBaseObjects)
    baseObjects.remove(object);
  removedBaseObjects.clear();
}
