#pragma once

#include "../../Engine.hpp"

class Engine;

class Screen {
	private:

	public:
		Screen();
		virtual ~Screen();

		virtual void update(sf::Time dt) = 0;
		virtual void render(sf::RenderTarget* target) = 0;
		virtual void processEvents() = 0;
		virtual void screenSwitch(Engine* engine) = 0;
};