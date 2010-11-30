#include "BaseObject.h"
#include "EngineManager.h"

BaseObject::BaseObject() {
  EngineManager::Instance().AddBaseObject(this);
}

BaseObject::~BaseObject() {
  EngineManager::Instance().RemoveBaseObject(this);
}
