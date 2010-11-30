#ifndef _ENGINE_MANAGER_H
#define _ENGINE_MANAGER_H

#include <SDL/SDL.h>

class EngineManager {
  public:
    ~EngineManager();
    static EngineManager& Instance() {
      static EngineManager instance;
      return instance;
    }

    bool Startup();

  protected:
    EngineManager();

    bool running;
    unsigned int lastFrame;
    SDL_Surface* surface;
};

#endif
