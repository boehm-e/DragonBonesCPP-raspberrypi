#include "./Background.h"
using namespace std;

Background::Background(string name) {
  settings  = Settings::getInstance();

  this->texture = new sf::Texture();
  if (!this->texture->loadFromFile("./data/landscapes/"+name+".png")){
    cout << "Background.cpp > could not load background" << endl;
  }

  background = new sf::Sprite();
  background->setTexture(*this->texture);

  background_loop = new sf::Sprite();
  background_loop->setTexture(*this->texture);
}

void Background::Draw(sf::RenderWindow * window) {
  if (background_loop->getGlobalBounds().width - settings->width + background_loop->getPosition().x < 0) {
    cout << "SWITCH" << endl;
    sf::Sprite *background_tmp = background_loop;
    background_loop = background;
    background = background_tmp;
  }

  window->draw(*this->background_loop);
  window->draw(*this->background);
}

void Background::Update(float deltaTime) {
  this->background->setPosition( this->background->getPosition().x-deltaTime*50 , 0);
  this->background_loop->setPosition( this->background->getPosition().x+this->background->getGlobalBounds().width, 0);
}
