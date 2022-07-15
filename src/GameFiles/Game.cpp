#include "Game.hpp"
#include "../Platform/Platform.hpp"

Game::Game() {
	util::Platform platform;
	this->window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "SFML works!", sf::Style::Fullscreen);
	this->window->setFramerateLimit(60);
	platform.setIcon(this->window->getSystemHandle());
}

void Game::run() {
	while (this->window->isOpen()) {
		Game::onClose();
		Game::render();
	}
}

void Game::render() {
	sf::CircleShape circle(25.0);
	circle.setPointCount(30);
	circle.setFillColor(sf::Color::White);
	circle.setPosition(this->window->getSize().x / 2, this->window->getSize().y - 100);
	this->window->clear(sf::Color::Black);
	this->window->draw(circle);
	this->window->display();
}

void Game::onClose() {
	sf::Event event;
	while (this->window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			this->window->close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			this->window->close();
		}
	}
}

Game::~Game() {
	delete this->window;
}