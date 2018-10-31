#include "./Game.h"


Character *Game::findCharacterByName(string name) {
	vector<Character*> _characters(this->characters.begin(), this->characters.end());
	for (auto character : _characters) {
		if (character->getName() == name) {
			return character;
		}
	}
	return nullptr;
}


void Game::Events() {
	sf::Event event;
	while (this->window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		this->window->close();

		if (event.type == sf::Event::KeyPressed) {
			findCharacterByName("sheep")->setAnimation("goat_idle_anim");
		}
	}
}

void Game::Start(bool fullscreen) {

	if (fullscreen == true) {
		window = new sf::RenderWindow(sf::VideoMode(this->width, this->height), "Magic Lamp", sf::Style::Fullscreen);
	}
	else  {
		window = new sf::RenderWindow(sf::VideoMode(this->width, this->height), "Magic Lamp");
	}
	this->window->setMouseCursorVisible(false);


	Background *background = new Background("landscape");


	Character *sheep = new Character("sheep", 0.25f);
	sheep->setAnimation("goat_sleep_idle_anim");
	sheep->setFlipX(true);
	sheep->setPosition(427.f, 360.f);
	characters.push_back(sheep);

	Character *dragon = new Character("dragon", 0.25f);
	dragon->setAnimation("stand");
	dragon->setPosition(227.f, 360.f);
	characters.push_back(dragon);


	sf::Clock clock;
	bool anim = true;
	while (this->window->isOpen())
	{
		float deltaTime = clock.restart().asSeconds();


		this->Events();

		for (auto &character : characters) {
			character->factory.update(deltaTime/2);
		}

		this->window->clear();

		background->Update(deltaTime);
		background->Draw(this->window);

		for (auto &character : characters) {
			this->window->draw(*character->armatureDisplay);
		}

		this->window->display();
	}
}
