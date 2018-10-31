#include <dragonBones/SFMLFactory.h>
#include <dragonBones/SFMLArmatureDisplay.h>
#include <math.h>
#include "../../../../SFML/src/dragonBones/SFMLArmatureProxy.h"
#include <iostream>

using namespace std;

class Character {
private:

public:
  Character (string name, float scale=1.0f);
  virtual ~Character (){}

  string name;
  sf::Texture texture;
  dragonBones::SFMLFactory factory;
  dragonBones::SFMLArmatureDisplay *armatureDisplay;
  dragonBones::SFMLArmatureProxy* armatureProxy;

  void setAnimation(string animName, int iterations=0);
  void setPosition(float x, float y);
  void setFlipX(bool flipX);
  string getName();
};
