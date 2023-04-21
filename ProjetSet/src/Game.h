#pragma once
#include <vector>
#include "Figure.h"



class Game {
private:
	std::vector<Figure> m_deck;
	std::vector<Figure> m_displayed;
	std::vector<unsigned long> m_indexSelected;
	std::vector<Figure> m_cardsSelected;

	std::vector<Figure> initDeck();
	void adaptCardsSelectionWithIndexed();
	bool isASet(const Figure& firstSelected, const Figure& secondSelected, const Figure& thirdSelected);
	bool isSelectedASet();
	void draw();

public:
	Game();

	void start();
	void drawCards(int);
	void shuffleDeck(int);
	void selectByIndex(unsigned long);
	void deSelectByIndex(unsigned long);
	void clearSelection();
	void confirmSelection();
	void listDisplayedCards();
	void removeSelectedCardsFromDisplay();
	void printDisplayedCards();
	bool isThereASet();
	int m_selectCursor;


	std::vector<Figure> getDeck() { return m_deck; }
	std::vector<Figure> getDisplayed() { return m_displayed; }
	std::vector<unsigned long> getSelectedIndexes() { return m_indexSelected; };
	std::vector<Figure> getSelectedCards() { return m_cardsSelected; };
};