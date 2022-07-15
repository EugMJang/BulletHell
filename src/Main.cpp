// #include "Platform/Platform.hpp"
#include "GameFiles/Game.hpp"
#include "Platform/Platform.hpp"

int main()
{
	#if defined(_DEBUG)
		std::cout << "Hello World!" << std::endl;
	#endif
	
	Game game;
	game.run();
}
