#pragma once
#include "Game.h"
#include "ClearConsole.h"

#include "Includes.h"


class UserInterface {
private:
	int m_cursorPos;
	Game& m_currentGame;
	bool m_cursorSelectionMode;
	const int MAX_IN_ROW{ 4 };

public:
	UserInterface(Game& currentGame);

	void greetPlayer();
	void playTheGame();

	void listDisplayedCards();
	void printDisplayedCards();
	void printCursorLine(int& cardCount);

	void selectByIndex(unsigned long index);
	void deselectByIndex(unsigned long index);

	void swapSelectionMode();

	

	int receiveIntInput();
	void treatIntInput(int intInput);

	char receiveCharInput();
	bool isCharInputValid(char input);
	void select(int toSelect);
	void treatCharInput(char charInput);

	void moveCursor(char direction);

};

