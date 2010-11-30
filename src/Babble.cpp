#include <iostream>

#include "ApplicationManager.h"
#include "EngineManager.h"
#include "Constants.h"

int main(int argc, char** argv) {
  std::cout << "Starting ApplicationManager..." << std::endl;

  ApplicationManager::Instance().Startup();
  if (!EngineManager::Instance().Startup())
    std::cout << "Error: Could not start EngineManager..." << std::endl;

  return 0;
}
