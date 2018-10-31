#include "./Character.h"
using namespace std;

Character::Character(string name, float scale) {

  this->name = name;
  texture.loadFromFile("data/characters/"+name+"/"+name+"_tex.png");
  factory.loadDragonBonesData("data/characters/"+name+"/"+name+"_ske.json");
  factory.loadTextureAtlasData("data/characters/"+name+"/"+name+"_tex.json", &texture);
  armatureDisplay = new dragonBones::SFMLArmatureDisplay("Armature");

  // SCALE
  armatureDisplay->getArmature()->getBone("root")->offset.scaleX = scale;
  armatureDisplay->getArmature()->getBone("root")->offset.scaleY = scale;

  armatureProxy = armatureDisplay->getArmatureProxy();
}

void Character::setAnimation(string animName, int iterations) {
  this->armatureDisplay->getAnimation()->fadeIn (animName, 0.4f, iterations);
}

void Character::setPosition(double x, double y) {
  this->x = x;
  this->y = y;
  this->armatureDisplay->setPosition({ this->x, this->y });
}

void Character::setFlipX(bool flipX) {
  armatureDisplay->getArmature()->getBone("root")->offset.scaleX = -1*fabs(armatureDisplay->getArmature()->getBone("root")->offset.scaleX);
}

string Character::getName() {
  return this->name;
}
