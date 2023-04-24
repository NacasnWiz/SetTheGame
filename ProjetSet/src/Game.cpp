#include "Game.h"



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
	,m_displayed{}, m_selectedIndexes{}
{
}

void Game::shuffleDeck(int seed = time(NULL)) {
	std::shuffle(m_deck.begin(), m_deck.end(), std::default_random_engine(seed));
}

void Game::start(){
	m_isOn = true;

	shuffleDeck();

	drawCards(12);
}

void Game::off() {
	m_isOn = false;
}

void Game::draw() {
	if (m_deck.empty()) {
		std::cout << "The deck is empty!\n";
		return;
	}

	m_displayed.push_back(Card(m_deck[0].getID()));
	m_deck.erase(m_deck.begin());
}

void Game::drawCards(int toDraw = 1) {

	for (int drawed{ 0 }; drawed < toDraw; drawed++) {
		draw();
	}
}

void Game::selectDisplayedCardByIndex(unsigned long index) {
	if (index >= m_displayed.size()) {
		std::cout << "There is no card to select here\n";
		return;
	} //Replace with an exception

	m_displayed[index].select();
	m_selectedIndexes.push_back(index);
}

void Game::deselectDisplayedCardByIndex(unsigned long index) {
	if (index >= m_displayed.size()) {
		std::cout << "There is no card to select here\n";
		return;
	} //Replace with an exception

	m_displayed[index].deSelect();
	removeIndexFromSelected(index);
}

void Game::removeIndexFromSelected(unsigned long index) {
	auto iteratorToDeselect{ std::find(m_selectedIndexes.begin(), m_selectedIndexes.end(), index) };
	if (iteratorToDeselect != m_selectedIndexes.end()) //there is such index in the selected indexes
	{
		m_selectedIndexes.erase(iteratorToDeselect);
	}
}

void Game::clearSelection() {
	for (unsigned long index : m_selectedIndexes) {
		m_displayed[index].deSelect();
	}

	m_selectedIndexes.clear();
}


bool Game::isASet(const Figure& firstSelected, const Figure& secondSelected, const Figure& thirdSelected) {
	//TODO: make little functions "is Color same or all different", etc. for readability
	if ((firstSelected.getColor() + secondSelected.getColor() + thirdSelected.getColor()) % 3 != 0) {
		return false;
	}

	if ((firstSelected.getShape() + secondSelected.getShape() + thirdSelected.getShape()) % 3 != 0) {
		return false;
	}

	if ((firstSelected.getFilling() + secondSelected.getFilling() + thirdSelected.getFilling()) % 3 != 0) {
		return false;
	}

	if ((firstSelected.getNumber() + secondSelected.getNumber() + thirdSelected.getNumber()) % 3 != 0) {
		return false;
	}

	return true;
}

bool Game::isSelectedASet() {
	if (m_selectedIndexes.size() != 3) {
		return false;
	}
	else {
		return isASet(m_displayed[m_selectedIndexes[0]], m_displayed[m_selectedIndexes[1]], m_displayed[m_selectedIndexes[2]]);
	}
}

void Game::removeSelectedCardsFromDisplay() {
	std::sort(m_selectedIndexes.begin(), m_selectedIndexes.end());
	std::reverse(m_selectedIndexes.begin(), m_selectedIndexes.end());
	for (unsigned long index : m_selectedIndexes) {
		m_displayed.erase(m_displayed.begin() + index);
	}
}

void Game::resolveConfirmSelection() {

	if (isSelectedASet()) {
		removeSelectedCardsFromDisplay();
		clearSelection();
		if (m_displayed.size() < 12) {
			drawCards(3);
		}
		std::cout << "\nIt is a set!\n\n";
	}
	else {
		std::cout << "Not a set!\n\n";
	}

}

bool Game::isThereASet() {
	bool output{ false };
	for (int firstCardIndex{ 0 }; firstCardIndex < 10; ++firstCardIndex) {
		for (int secondCardIndex{ firstCardIndex + 1 }; secondCardIndex < 11; ++secondCardIndex) {
			for (int thirdCardIndex{ secondCardIndex + 1 }; thirdCardIndex < 12; ++thirdCardIndex) {
				output = isASet(m_displayed[firstCardIndex], m_displayed[secondCardIndex], m_displayed[thirdCardIndex]);
				if (output) {
					return true;
				}
			}
		}
	}
	return output;
}