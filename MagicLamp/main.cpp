#include <iostream>
#include "src/Game.h"

using namespace std;

int main()
{

	bool fullscreen;
	#ifdef __aarch64__
	fullscreen = true;
	#else
	fullscreen = false;
	#endif

	Game game;
	game.Start(fullscreen);

	return 0;
}
