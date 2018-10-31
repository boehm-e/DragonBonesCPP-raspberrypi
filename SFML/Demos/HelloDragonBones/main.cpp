#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>
#include "src/Character.h"

using namespace std;

list<Character*> characters;

int main()
{

	#ifdef __arm__
	sf::RenderWindow window(sf::VideoMode(640, 360), "Magic Lamp", sf::Style::Fullscreen);
	cout << "---- FULLSCREEN" << endl;
  #endif

	#ifndef __arm__
	sf::RenderWindow window(sf::VideoMode(640, 360), "Magic Lamp");
	cout << "---- NOT FULLSCREEN" << endl;
	#endif
	window.setFramerateLimit(60);


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
		for (auto &character : characters) {
			window.draw(*character->armatureDisplay);
		}

		window.display();
	}

	return 0;
}
