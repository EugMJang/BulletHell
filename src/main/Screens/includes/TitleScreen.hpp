#pragma once

#include "Screen.hpp"

class TitleScreen : public Screen {
	public:
		void update(sf::Time dt);
		void render(sf::RenderTarget* target);
		void processEvents();
		void screenSwitch(Engine* engine);
};