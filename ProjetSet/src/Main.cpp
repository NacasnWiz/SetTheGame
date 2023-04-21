#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Figure.h"
#include "Game.h"



void manuallyPlayTheGame(Game& myGame) {
	myGame.listDisplayedCards();

	unsigned long indexSelect{};

	while (myGame.getSelectedIndexes().size() < 3) {
		std::cout << "\nSelect a card by index: ";
		std::cin >> indexSelect;
		if (indexSelect == 100) {
			return;
		}
		if (indexSelect == -1) {
			if (myGame.isThereASet()) {
				std::cout << "There IS a set! You can find it!\n";
				myGame.listDisplayedCards();
			}
			else {
				std::cout << "There is, in fact, no set.\n";
			}
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
