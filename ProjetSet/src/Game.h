#pragma once
#include <vector>
#include "Figure.h"

class Game {
private:
	std::vector<int> m_deck;
	std::vector<Figure> m_displayed;
	std::vector<unsigned long> m_indexSelected;
	std::vector<Figure> m_cardsSelected;

	std::vector<int> initDeck();
	void adaptCardsSelectionWithIndexed();
	bool isSelectedASet();

public:
	Game();

	void start();
	void drawFigures(int);
	void shuffleDeck(int);
	void selectByIndex(unsigned long);
	void deSelectByIndex(unsigned long);
	void clearSelection();
	void confirmSelection();

	std::vector<int> getDeck() { return m_deck; }
	std::vector<Figure> getDisplayed() { return m_displayed; }
	std::vector<unsigned long> getSelectedIndexes() { return m_indexSelected; };
	std::vector<Figure> getSelectedCards() { return m_cardsSelected; };
};