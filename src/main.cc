#include "EventHandler.h"
#include "SFMLStub.h"

class EV : public EventHandler {
 public:
  EV(SFMLStub& sfmlStub) : sfmlStub(sfmlStub) {}

  void newEvent(const sf::Event& event) override {
    if (event.type == sf::Event::KeyReleased) {
      if (event.key.code == sf::Keyboard::Escape) {
        sfmlStub.stop();
      }
    }
  }

 private:
  SFMLStub& sfmlStub;
};

int main(const int    argc,
         const char** argv) {
  SFMLStub sfmlStub("test");

  EV ev(sfmlStub);
  sfmlStub.addEventHandler(&ev);

  sfmlStub.run();

  sfmlStub.run();
}
