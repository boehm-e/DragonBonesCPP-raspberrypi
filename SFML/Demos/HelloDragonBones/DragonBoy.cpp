/** @file DragonBoy.cpp
 ** @author Piotr Krupa (piotrkrupa06@gmail.com)
 ** @license MIT License
 **/

#include <SFML/Graphics.hpp>

#include <dragonBones/SFMLFactory.h>
#include <dragonBones/SFMLArmatureDisplay.h>
#include <iostream>

using namespace std;


int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 768), "My window");
	window.setFramerateLimit(60);

	dragonBones::SFMLFactory factory;

	sf::Texture texture;
	texture.loadFromFile("data/sheep/Sheep_Ani_tex.png");

	factory.loadDragonBonesData("data/sheep/Sheep_Ani_ske.json");
	factory.loadTextureAtlasData("data/sheep/Sheep_Ani_tex.json", &texture);

	auto armatureDisplay = new dragonBones::SFMLArmatureDisplay("Armature");
	cout << "ARMATURE NAME : " << armatureDisplay << endl;
	armatureDisplay->getAnimation()->fadeIn ("goat_sleep_idle_anim", 0.4f, -1);
	armatureDisplay->setPosition({ 512.f, 768.f });


	bool anim = false;

	sf::Clock clock;

	while (window.isOpen())
	{
		float deltaTime = clock.restart().asSeconds();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

				if (event.type == sf::Event::KeyPressed) {
					cout << "OKKK" << endl;
					if (anim == true) {
						anim = false;
						armatureDisplay->getAnimation()->fadeIn ("goat_idle_anim", 0.4f, -1);
					} else {
						anim = true;
						armatureDisplay->getAnimation()->fadeIn ("goat_sleep_idle_anim", 0.4f, -1);
					}
				}
		}

		factory.update(deltaTime);

		window.clear();
		window.draw(*armatureDisplay);
		window.display();
	}

	return 0;
}
