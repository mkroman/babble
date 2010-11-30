#ifndef _BASE_OBJECT_H
#define _BASE_OBJECT_H

#include <SDL/SDL.h>

class BaseObject {
  public:
    BaseObject();
    virtual ~BaseObject();

    virtual void EnterFrame(float dt) {}
    virtual void Draw(SDL_Surface* const mainSurface) {}
};

#endif
