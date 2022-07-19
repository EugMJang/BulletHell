#include "includes/GameScreen.hpp"
#include "includes/TitleScreen.hpp"
#include <iostream>

void GameScreen::update(sf::Time dt) {
	dt.asSeconds();
	std::cout << "gamescreen" << std::endl;
}

void GameScreen::render(sf::RenderTarget* target) {
	target->clear(sf::Color::Red);
}

void GameScreen::processEvents() {

}

void GameScreen::screenSwitch(Engine* engine) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		engine->screenSwitch(new TitleScreen());
	}
}