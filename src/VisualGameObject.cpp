#include "VisualGameObject.h"

VisualGameObject::VisualGameObject(const std::string& filename) :
  BaseObject(),
  surrface(NULL),
  x(0), y(0)
{
  SDL_Surface* temp = NULL;

  if ((temp = IMG_Load(filename)) == NULL)
    throw std::string("Failed to load image.");

  surface = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
}
