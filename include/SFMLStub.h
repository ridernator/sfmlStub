#pragma once

#include <string>

#include "EventHandler.h"

#include <SFML/Graphics/RenderWindow.hpp>

class SFMLStub {
 public:
  SFMLStub(const std::string& title);

  ~SFMLStub();

  void run();

  void addEventHandler(EventHandler* eventHandler);

  void close();

 private:
  const std::string title;

  sf::RenderWindow* window = nullptr;

  EventHandler* eventHandler = nullptr;

  bool shouldClose = false;
};
