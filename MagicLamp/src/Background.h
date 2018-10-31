#include <SFML/Graphics.hpp>
#include <iostream>
#include "Settings.h"

using namespace std;

class Background {

public:
  Background(string name);

  void Draw(sf::RenderWindow * window);
  void Update(float deltaTime);

  sf::Texture *texture;
  sf::Sprite *background;
  sf::Sprite *background_loop;

  Settings *settings;
};
