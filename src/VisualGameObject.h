#ifndef _VISUAL_GAME_OBJECT_H
#define _VISUAL_GAME_OBJECT_H

#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "BaseObject.h"

class VisualGameObject : public BaseObject {
  public:
    VisualGameObject(const std::string& filename);
    virtual ~VisualGameObject();
    virtual void Draw(SDL_Surface* const mainSurface);

  protected:
    SDL_Surface* surface;
    float x;
    float y;
};

#endif
