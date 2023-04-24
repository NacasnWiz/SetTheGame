#include "Interface.h"


UserInterface::UserInterface(Game&currentGame) :
	m_currentGame{ currentGame },
	m_cursorSelectionMode{ false }, m_cursorPos { 0 }
{
	greetPlayer();
}

void UserInterface::greetPlayer() {
	std::cout << "Greetings !\n\n";

	//Explain the rules

	//Explain the input type for the game
	std::cout << "Albeit rare (3% chance average), cases could occur that there is no set displayed.";
	std::cout << " You can call it by entering - 1\n\n";


	

	std::cout << "When you're ready to play, enter any key...\n";
	char x{};
	std::cin >> x;

	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


	listDisplayedCards();
}

void UserInterface::playTheGame() {
	while (m_currentGame.m_isOn) {
		int intInput{ 0 };
		char charInput{ 0 };

		while (m_currentGame.getSelectedIndexes().size() < 3) {
			if (m_cursorSelectionMode) {
				charInput = receiveCharInput();
				treatCharInput(charInput);
				listDisplayedCards();
				std::cout << m_textMessage;
				m_textMessage.clear();

			}
			else {
				intInput = receiveIntInput();
				treatIntInput(intInput);
				listDisplayedCards();
				std::cout << m_textMessage;
				m_textMessage.clear();

			}
		}

		confirmSelection();
		m_currentGame.clearSelection();

		std::cout << "\n[You can stop playing by picking card 100]\n";
		playTheGame();
	}
}

void UserInterface::listDisplayedCards() {
	cls();
	std::cout << "Current cards are:\n\n";
	printDisplayedCards();
}

void UserInterface::printDisplayedCards() {
	int inRowCount{ 0 };
	int cardCount{ 0 };

	for (const Card& card : m_currentGame.getDisplayed()) {
		std::cout << card << "  ";
		++inRowCount;
		if (inRowCount == MAX_IN_ROW) {
			std::cout << '\n';
			if (m_cursorSelectionMode) {
				printCursorLine(cardCount);
			}
			std::cout << '\n';
			inRowCount = 0;
		}
	}
}

void UserInterface::printCursorLine(int& cardCount) {
	for (int count{ 0 }; count < MAX_IN_ROW; ++count) {
		if (cardCount == m_cursorPos) {
			std::cout << ' ' << '^' << ' ' << ' ' << ' ' << ' ' << ' ';
		}
		else {
			std::cout << ' ' << ' ' << ' ' << ' ' << ' ' << ' ' << ' ';
		}
		std::cout << ' ' << ' ' << ' ';
		++cardCount;
	}
}

void UserInterface::confirmSelection() {
	m_currentGame.resolveConfirmSelection();
}

void UserInterface::toggleSelectDisplayedCard(unsigned long index) {
	if (m_currentGame.getDisplayed()[index].isSelected()) {
		m_currentGame.deselectDisplayedCardByIndex(index);
	}
	else {
		m_currentGame.selectDisplayedCardByIndex(index);
	}
}


void UserInterface::swapSelectionMode() {
	if (m_cursorSelectionMode) {
		std::cout << "You can swap back to cursor selection by entering 0\n";
	}
	else {
		std::cout << "You can swap back to selection by index entering \'o\'\n";
	}
	m_cursorSelectionMode = !m_cursorSelectionMode;
}


int UserInterface::receiveIntInput() {
	int intInput{};

	
	std::cout << "Select a card by index (range 1-12): ";
	std::cin >> intInput;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return receiveIntInput();
	}

	return intInput;
}


void UserInterface::treatIntInput(int intInput) {

	if (intInput == 0) {
		swapSelectionMode();
		return;
	}

	if (intInput == 100) {
		m_currentGame.off();
		return;
	}

	if (intInput == -1) {
		if (m_currentGame.isThereASet()) {
			m_textMessage = "There IS a set! You can find it!\n";
		}
		else {
			std::cout << "\nThere is, in fact, no set.\n";
			m_currentGame.drawCards(3);
		}
	}

	else {
		toggleSelectDisplayedCard(intInput - 1);
	}
}

char UserInterface::receiveCharInput() {
	char charInput{};

	std::cout << "Move cursor with ZQSD, select with \'e\': ";
	std::cin >> charInput;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return receiveCharInput();
	}

	if (isCharInputValid(charInput)) {
		return charInput;
	}
	else {
		return receiveCharInput();
	}

}

bool UserInterface::isCharInputValid(char input) {
	return (input >= 'A' && input <= 'z');
}

void UserInterface::treatCharInput(char charInput) {
	if (charInput == 'o' || charInput == 'O') {
		swapSelectionMode();
		return;
	}
	if (charInput == 'e' || charInput == 'E') {
		toggleSelectDisplayedCard(m_cursorPos);
	}
	else {
		moveCursor(charInput);
	}
}


void UserInterface::moveCursor(char direction) {
	switch (direction) {
	case 'z':
	case 'Z':
		m_cursorPos -= MAX_IN_ROW;
		break;
	case 'q':
	case 'Q':
		--m_cursorPos;
		break;
	case 's':
	case 'S':
		m_cursorPos += MAX_IN_ROW;
		break;
	case 'd':
	case 'D':
		++m_cursorPos;
		break;
	default:
		std::cout << "Invalid input, please restrict to ZQSD, \'e\'to select.\n";
	}

	if (m_cursorPos < 0) {
		m_cursorPos += m_currentGame.getDisplayed().size();
	}
	if (m_cursorPos >= m_currentGame.getDisplayed().size()) {
		m_cursorPos -= m_currentGame.getDisplayed().size();
	}
}