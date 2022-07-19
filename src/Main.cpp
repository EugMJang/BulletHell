#include "main/Engine.hpp"

int main()
{
	#if defined(_DEBUG)
		std::cout << "Hello World!" << std::endl;
	#endif

	Engine engine;
	engine.run();
}
