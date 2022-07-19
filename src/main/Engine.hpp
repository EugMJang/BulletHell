#pragma once

#include "Screens/includes/Screen.hpp"

class Screen;

class Engine {
	private:
		sf::RenderWindow* window;
		sf::Time fps;
		Screen* curr_screen;

		void processEvents();
		void render();
		void update(sf::Time dt);
	public:
		Engine();
		~Engine();

		void run();
		void screenSwitch(Screen* screen);
};