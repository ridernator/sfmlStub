#include "SFMLStub.h"

#include <string>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>

SFMLStub::SFMLStub(const std::string& title) : title(title) {
}

SFMLStub::~SFMLStub() {
  if (window != nullptr) {
    close();
  }
}

void SFMLStub::run() {
  window = new sf::RenderWindow(sf::VideoMode::getFullscreenModes()[0], title, sf::Style::Fullscreen);

  sf::View view = window->getDefaultView();
  view.setRotation(180);
  window->setView(view);

  window->display();

  sf::Event event;

  while ((window->isOpen()) && (!shouldClose)) {
    while (window->pollEvent(event)) {
      if (eventHandler != nullptr) {
        eventHandler->newEvent(event);
      }
    }
  }

  delete window;
}

void SFMLStub::close() {
  shouldClose = true;
}

void SFMLStub::addEventHandler(EventHandler* eventHandler) {
  this->eventHandler = eventHandler;
}