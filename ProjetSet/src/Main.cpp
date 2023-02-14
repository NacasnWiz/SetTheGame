#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Figure.h"
#include "Game.h"

/*
//foo.cpp
#include <gtkmm.h>

int main(int argc, char** argv)
{
    auto app = Gtk::Application::create(argc, argv);

    Gtk::Window window;
    window.set_default_size(600, 400);

    return app->run(window);
}
*/


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
