#include "Game.h"
#include <algorithm>
#include <random>
#include <iostream>


std::vector<Figure> Game::initDeck() {
	std::vector<Figure> output;
	Figure newCard{ 0 };

	for (int i{ 0 }; i < 81; i++) {
		newCard = Figure{ i };
		output.push_back(newCard);
	}

	return output;
}

Game::Game()
	: m_deck {initDeck()}
	,m_displayed{}, m_indexSelected{}, m_cardsSelected{}
{
}

void Game::shuffleDeck(int seed = time(NULL)) {
	std::shuffle(m_deck.begin(), m_deck.end(), std::default_random_engine(seed));
}

void Game::start(){
	shuffleDeck();

	drawCards(12);
}

void Game::draw() {
	if (m_deck.empty()) {
		std::cout << "The deck is empty!\n";
		return;
	}

	m_displayed.push_back(m_deck[0]);
	m_deck.erase(m_deck.begin());
}

void Game::drawCards(int toDraw = 1) {

	for (int drawed{ 0 }; drawed < toDraw; drawed++) {
		draw();
	}
}

void Game::selectByIndex(unsigned long index) {
	if (index >= m_displayed.size()) {
		std::cout << "There is no card to select here\n";
		return;
	}
	if (std::find(m_indexSelected.begin(), m_indexSelected.end(), index) == m_indexSelected.end()){
		m_indexSelected.push_back(index);
	}
}

void Game::deSelectByIndex(unsigned long toDeselect) {
	auto iteratorToDeselect{ std::find(m_indexSelected.begin(), m_indexSelected.end(), toDeselect) };
	if (iteratorToDeselect != m_indexSelected.end()) {
		m_indexSelected.erase(iteratorToDeselect);
	}
}

void Game::clearSelection() {
	m_indexSelected.clear();
	m_cardsSelected.clear();
}

void Game::adaptCardsSelectionWithIndexed() {
	m_cardsSelected.clear();
	for (unsigned long index : m_indexSelected) {
		m_cardsSelected.push_back(m_displayed[index]);
	}
}

bool Game::isSelectedASet() {
	if (m_cardsSelected.size() != 3) {
		return false;
	}

	//TODO: make little functions "is Color same or all different", etc. for readability
	if ((m_cardsSelected[0].getColor() + m_cardsSelected[1].getColor() + m_cardsSelected[2].getColor()) % 3 != 0) {
		return false;
	}

	if ((m_cardsSelected[0].getShape() + m_cardsSelected[1].getShape() + m_cardsSelected[2].getShape()) % 3 != 0) {
		return false;
	}

	if ((m_cardsSelected[0].getFilling() + m_cardsSelected[1].getFilling() + m_cardsSelected[2].getFilling()) % 3 != 0) {
		return false;
	}

	if ((m_cardsSelected[0].getNumber() + m_cardsSelected[1].getNumber() + m_cardsSelected[2].getNumber()) % 3 != 0) {
		return false;
	}

	return true;
}

void Game::removeSelectedCardsFromDisplay() {
	std::sort(m_indexSelected.begin(), m_indexSelected.end());
	std::reverse(m_indexSelected.begin(), m_indexSelected.end());
	for (unsigned long index : m_indexSelected) {
		m_displayed.erase(m_displayed.begin() + index);
	}
}

void Game::confirmSelection() {
	adaptCardsSelectionWithIndexed();

	if (isSelectedASet()) {
		removeSelectedCardsFromDisplay();
		clearSelection();
		drawCards(3);
		std::cout << "\nIt is a set!\n\n";
	}
	else {
		std::cout << "Not a set!\n\n";
	}
}

//Experimental
void printCards(std::vector<Figure> cards) {
	for (Figure card : cards) {
		std::cout << card.getColor() << "  ";
	}
	std::cout << "\n";

	for (Figure card : cards) {
		std::cout << card.getShape() << "  ";
	}
	std::cout << "\n";

	for (Figure card : cards) {
		std::cout << card.getFilling() << "  ";
	}
	std::cout << "\n";

	for (Figure card : cards) {
		std::cout << card.getNumber() << "  ";
	}
	std::cout << "\n";

	for (Figure card : cards) {
		std::cout << card.getID() << " ";
	}
	std::cout << "\n";
}

void Game::listDisplayedCards() {
	std::cout << "\nCurrent cards are: \n";
	printCards(m_displayed);
}