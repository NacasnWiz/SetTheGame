#pragma once
#include "Figure.h"
#include "Includes.h"


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

	bool m_isOn{ false };

	void start();
	void off();
	void drawCards(int);
	void shuffleDeck(int);
	void clearSelection();
	bool isThereASet();

	void addIndexToSelected(unsigned long index);
	void removeIndexFromSelected(unsigned long index);
	
	//These have to be renamed but interfally act as Game functions and should be called by Interface
	void removeSelectedCardsFromDisplay();
	void confirmSelection();


	std::vector<Figure> getDeck() { return m_deck; }
	std::vector<Figure> getDisplayed() { return m_displayed; }
	std::vector<unsigned long> getSelectedIndexes() { return m_indexSelected; };
	std::vector<Figure> getSelectedCards() { return m_cardsSelected; };

};