#include <iostream>

#include "ApplicationManager.h"

ApplicationManager::ApplicationManager() {
  // …
}

ApplicationManager::~ApplicationManager() {
  // …
}

void ApplicationManager::Startup() {
  std::cout << "Started ApplicationManager..." << std::endl;
  try {
    VisualGameObject* figure = new VisualGameObject("figure.png");
  } catch (std::string& e) {
    std::cout << "Error! " << std::endl;
  }
}
