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
  int width = 640;
  int height = 360;

  list<Character*> characters;

  void Start(bool fullscreen);
  void Events();
  Character *findCharacterByName(string name);
};
