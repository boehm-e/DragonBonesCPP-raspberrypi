#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>
#include "./Character.h"
#include "./Background.h"
using namespace std;


using namespace std;

class Game {

public:
  sf::Texture *texture;
  sf::RenderWindow * window;
   // projector resolution
  float width = 854.0f;
  float height = 480.0f;

  list<Character*> characters;

  void Start(bool fullscreen);
  void Events();
  Character *findCharacterByName(string name);
};
