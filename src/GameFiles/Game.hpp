#pragma once

class Game {
	private:
		sf::RenderWindow* window;
		void onClose();
		void render();
	public:
		Game();
		~Game();
		void run();
};