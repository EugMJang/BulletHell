#include "includes/TitleScreen.hpp"
#include "includes/GameScreen.hpp"

void TitleScreen::update(sf::Time dt) {
	dt.asSeconds();
	std::cout << "titlescreen" << std::endl;
}

void TitleScreen::render(sf::RenderTarget* target) {
	target->clear();
}

void TitleScreen::processEvents() {

}

void TitleScreen::screenSwitch(Engine* engine) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		engine->screenSwitch(new GameScreen());
	}
}