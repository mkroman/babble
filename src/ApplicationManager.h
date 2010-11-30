#ifndef _APPLICATION_MANAGER_H
#define _APPLICATION_MANAGER_H

#include "VisualGameObject.h"
#include "EngineManager.h"

class ApplicationManager {
  public:
    ~ApplicationManager();
    static ApplicationManager& Instance() {
      static ApplicationManager instance;
      return instance;
    }

    void Startup();

  protected:
    ApplicationManager();
};

#endif
