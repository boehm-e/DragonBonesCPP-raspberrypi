#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>
#include "src/Character.h"

using namespace std;

list<Character*> characters;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 768), "My window");
	window.setFramerateLimit(60);


	Character *sheep = new Character("sheep", 0.5f);
	sheep->setAnimation("goat_sleep_idle_anim");
	sheep->setPosition(627.f, 480.f);
	characters.push_back(sheep);

	Character *sheep2 = new Character("sheep", 0.5f);
	sheep2->setFlipX(true);
	sheep2->setAnimation("goat_idle_anim");
	sheep2->setPosition(227.f, 480.f);
	characters.push_back(sheep2);


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

		cout << deltaTime << endl;


		for (auto &character : characters) {
			character->factory.update(deltaTime);
		}

		window.clear();
		for (auto &character : characters) {
				window.draw(*character->armatureDisplay);
		}

		window.display();
	}

	return 0;
}
