#ifndef _ENGINE_MANAGER_H
#define _ENGINE_MANAGER_H

#include <SDL/SDL.h>
#include <list>

class BaseObject;

typedef std::list<BaseObject*> BaseObjectList;

class EngineManager {
  public:
    ~EngineManager();
    static EngineManager& Instance() {
      static EngineManager instance;
      return instance;
    }

    bool Startup();
    void AddBaseObject(BaseObject* object);
    void RemoveBaseObject(BaseObject* object);

  protected:
    EngineManager();

    void AddBaseObjects();
    void RemoveBaseObjects();

    bool running;
    BaseObjectList baseObjects;
    BaseObjectList addedBaseObjects;
    BaseObjectList removedBaseObjects;
    SDL_Surface* surface;
};

#endif
