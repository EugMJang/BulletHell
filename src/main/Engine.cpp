#include "Engine.hpp"
#include "../src/Platform/Platform.hpp"
#include <iostream>
#include "Screens/includes/TitleScreen.hpp"

Engine::Engine() {
	util::Platform platform;
	window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "SFML works!", sf::Style::Fullscreen);
	fps = sf::seconds(1.0f / 60);
	platform.setIcon(window->getSystemHandle());
	curr_screen = new TitleScreen();
}

void Engine::run() {
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (window->isOpen()) {
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > fps) {
			timeSinceLastUpdate -= fps;
			processEvents();
			curr_screen->screenSwitch(this);
			update(fps);
		}
		render();
	}
}

void Engine::render() {
	window->clear(sf::Color::Black);

	curr_screen->render(window);

	window->display();
}

void Engine::update(sf::Time dt) {
	curr_screen->update(dt);
}

void Engine::processEvents() {
	sf::Event event;
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window->close();
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		window->close();
	}
	curr_screen->processEvents();
}

void Engine::screenSwitch(Screen* screen) {
	delete curr_screen;
	curr_screen = screen;
}

Engine::~Engine() {
	delete window;
}