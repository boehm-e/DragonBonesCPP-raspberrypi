#include "./Character.h"
using namespace std;

Character::Character(string name, float scale) {

  texture.loadFromFile("data/sheep/"+name+".png");
  factory.loadDragonBonesData("data/sheep/"+name+"_ske.json");
  factory.loadTextureAtlasData("data/sheep/"+name+"_tex.json", &texture);
  armatureDisplay = new dragonBones::SFMLArmatureDisplay("Armature");

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
