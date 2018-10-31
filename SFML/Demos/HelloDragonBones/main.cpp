#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>
#include "src/Character.h"

using namespace std;

list<Character*> characters;


sf::Sprite &createBackground() {
	sf::Texture *texture = new sf::Texture();
	if (!texture->loadFromFile("./data/landscapes/landscape.png")){
		cout << "COULD NOT LOAD BACKGROUND" << endl;
	}
	sf::Sprite *background = new sf::Sprite();
	background->setTexture(*texture);
	background->setScale(0.4, 0.4);
	return *background;
}

int main()
{

	#ifdef __aarch64__
	cout << "---- FULLSCREEN" << endl;
	sf::RenderWindow window(sf::VideoMode(640, 360), "Magic Lamp", sf::Style::Fullscreen);
	#else
	sf::RenderWindow window(sf::VideoMode(640, 360), "Magic Lamp");
	cout << "---- NOT FULLSCREEN" << endl;
	#endif
	window.setMouseCursorVisible(false);


	sf::Sprite background = createBackground();


	Character *sheep = new Character("sheep", 0.2f);
	sheep->setAnimation("goat_sleep_idle_anim");
	sheep->setFlipX(true);
	sheep->setPosition(427.f, 360.f);
	characters.push_back(sheep);

	Character *dragon = new Character("dragon", 0.2f);
	dragon->setAnimation("stand");
	dragon->setPosition(227.f, 360.f);
	characters.push_back(dragon);


	sf::Clock clock;
	bool anim = true;
	while (window.isOpen())
	{
		float deltaTime = clock.restart().asSeconds();


		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			window.close();

			if (event.type == sf::Event::KeyPressed) {
				if (anim == true) {
					anim = false;
					sheep->setAnimation("goat_idle_anim");
				} else {
					anim = true;
					sheep->setAnimation("goat_sleep_idle_anim");
				}
			}
		}

		for (auto &character : characters) {
			character->factory.update(deltaTime/2);
		}

		window.clear();
		background.setPosition( background.getPosition().x-deltaTime*10 , 0);
		window.draw(background);
		for (auto &character : characters) {
			window.draw(*character->armatureDisplay);
		}

		window.display();
	}

	return 0;
}
