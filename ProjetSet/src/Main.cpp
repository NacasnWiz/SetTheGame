#include "Includes.h"

#include "Figure.h"
#include "Game.h"
#include "Interface.h"


int main(int argc, char** argv) {
	std::srand(time(0));

	Game mG{};
	mG.start();
	UserInterface playerInterface(mG);

	playerInterface.playTheGame();
	
	return 0;
}
