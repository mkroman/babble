#include "VisualGameObject.h"

VisualGameObject::VisualGameObject(const std::string& filename) :
  BaseObject(),
  surface(NULL),
  x(0), y(0)
{
  SDL_Surface* temp = NULL;

  if ((temp = IMG_Load(filename.c_str())) == NULL)
    throw std::string("Failed to load image.");

  surface = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
}

VisualGameObject::~VisualGameObject() {
  if (surface) {
    SDL_FreeSurface(surface);
    surface = NULL;
  }
}

void VisualGameObject::Draw(SDL_Surface* const mainSurface) {

}
