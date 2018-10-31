#include "./Character.h"
using namespace std;

Character::Character(string name, float scale) {


  cout << " == DEBUG 1" << endl;
  texture.loadFromFile("data/characters/"+name+"/"+name+"_tex.png");
  cout << " == DEBUG 2" << endl;
  factory.loadDragonBonesData("data/characters/"+name+"/"+name+"_ske.json");
  cout << " == DEBUG 3" << endl;
  factory.loadTextureAtlasData("data/characters/"+name+"/"+name+"_tex.json", &texture);
  cout << " == DEBUG 4" << endl;
  armatureDisplay = new dragonBones::SFMLArmatureDisplay("Armature");
  cout << " == DEBUG 5" << endl;

  armatureDisplay->getArmature()->getBone("root")->offset.scaleX = scale;
  armatureDisplay->getArmature()->getBone("root")->offset.scaleY = scale;

  // SCALE
  armatureProxy = armatureDisplay->getArmatureProxy();
}

void Character::setAnimation(string animName, int iterations) {
  this->armatureDisplay->getAnimation()->fadeIn (animName, 0.4f, iterations);
}

void Character::setPosition(float x, float y) {
  this->armatureDisplay->setPosition({ x, y });
}

void Character::setFlipX(bool flipX) {
  armatureDisplay->getArmature()->getBone("root")->offset.scaleX = -1*fabs(armatureDisplay->getArmature()->getBone("root")->offset.scaleX);
}
