#include <iostream>

#include "Constants.h"
#include "EngineManager.h"

int main(int argc, char** argv) {
  std::cout << "Starting EngineManager ..." << std::endl;

  if (!EngineManager::Instance().Startup())
    std::cout << "Error: Could not start EngineManager ..." << std::endl;

  return 0;
}
