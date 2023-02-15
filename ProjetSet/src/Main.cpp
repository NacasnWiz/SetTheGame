#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Figure.h"
#include "Game.h"



void manuallyPlayTheGame(Game myGame) {
	myGame.listDisplayedCards();

	unsigned long indexSelect{};

	for (unsigned long i{ 0 }; i < 3; i++) {
		std::cout << "\nSelect a card by index: ";
		std::cin >> indexSelect;
		if (indexSelect == 100) {
			return;
		}
		else {
			myGame.selectByIndex(indexSelect);
		}
	}

	myGame.confirmSelection();
	myGame.clearSelection();
	
	std::cout << "[You can stop playing by picking card 100]\n";
	manuallyPlayTheGame(myGame);
}

int main(int argc, char** argv) {
	std::srand(time(0));

	Game mG{};
	mG.start();
	manuallyPlayTheGame(mG);
	
	return 0;
}
