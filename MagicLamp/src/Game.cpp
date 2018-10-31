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
			findCharacterByName("sheep")->setAnimation("goat_walk_anim");
		}
	}
}

void Game::Start(bool fullscreen) {
	settings = Settings::getInstance();
	if (fullscreen == true) {
		window = new sf::RenderWindow(sf::VideoMode(settings->width, settings->height), "Magic Lamp", sf::Style::Fullscreen);
	}
	else  {
		window = new sf::RenderWindow(sf::VideoMode(settings->width, settings->height), "Magic Lamp");
	}
	this->window->setMouseCursorVisible(false);


	Background *background = new Background("castle");


	Character *rooster = new Character("rooster", 0.35);
	rooster->setAnimation("rooster_walk_anim");
	rooster->setPosition(427.f, settings->height);
	rooster->setFlipX(true);
	characters.push_back(rooster);

	Character *sheep = new Character("sheep", 0.35);
	sheep->setAnimation("goat_sleep_idle_anim");
	// sheep->setFlipX(true);
	sheep->setPosition(227.f, settings->height);
	characters.push_back(sheep);


	sf::Clock clock;
	while (this->window->isOpen())
	{
		float deltaTime = clock.restart().asSeconds();


		this->Events();


		this->window->clear();

		background->Update(deltaTime);
		background->Draw(this->window);
		rooster->x -= deltaTime*50;
		rooster->setPosition(rooster->x, rooster->y);
		sheep->x += deltaTime*50;
		sheep->setPosition(sheep->x, sheep->y);

		for (auto &character : characters) {
			character->factory.update(deltaTime/2);
			this->window->draw(*character->armatureDisplay);
		}

		this->window->display();
	}
}
