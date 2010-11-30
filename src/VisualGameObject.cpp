#include "VisualGameObject.h"
#include <iostream>

VisualGameObject::VisualGameObject(const std::string& filename) :
  BaseObject(),
  surface(NULL),
  x(0), y(0)
{
  SDL_Surface* temp = NULL;

  if ((temp = IMG_Load(filename.c_str())) == NULL)
    throw std::string("Could not load image.");
  else {
    if (surface != NULL)
      SDL_FreeSurface(surface);

    surface = temp;
  }
}

VisualGameObject::~VisualGameObject() {
  if (surface) {
    SDL_FreeSurface(surface);
    surface = NULL;
  }
}

void VisualGameObject::Draw(SDL_Surface* const mainSurface) {
  if (surface != NULL) {
    SDL_Rect destRect = { int(x), int(y), 0, 0 };

    SDL_BlitSurface(surface, NULL, mainSurface, &destRect);
  }
}
