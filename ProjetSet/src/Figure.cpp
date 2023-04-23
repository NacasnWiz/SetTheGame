#include "Figure.h"

Figure::Figure(Color color, Shape shape, Filling filling, int number) 
	: m_color{color}, m_shape{shape}, m_filling{filling}, m_number{number},
	m_ID{ color * 27 + shape * 9 + filling * 3 + number }
{
}

Figure::Figure(int ID)
	: m_ID{ ID },
	m_color{ static_cast<Color>((ID % 81) / 27) },
	m_shape{ static_cast<Shape>((ID % 27) / 9) },
	m_filling{ static_cast<Filling>((ID % 9) / 3) },
	m_number { ID % 3 }
{
}


std::ostream& operator<<(std::ostream& out, const Figure& figure) {
	char symbol{};

	switch (figure.m_shape) {
	case triangle:
		symbol = 'a';
		break;
	case square:
		symbol = 'b';
		break;
	case circle:
		symbol = 'c';
		break;
	default:
		symbol = '?';
	}

	if (figure.m_filling == hatched) {
		symbol += 'A' - 'a';
	}

	switch (figure.m_color) {
	case blue:
		out << '1';
		break;
	case red:
		out << '2';
		break;
	case green:
		out << '3';
		break;
	default:
		out << "color?";
	}

	int trailingSpacesCount{ 0 };

	for (int symbolCount{ 0 }; symbolCount < 3; ++symbolCount) {
		if (symbolCount <= figure.m_number){
			out << symbol;
			if (figure.m_filling == full) {
				out << '*';
			}
			else {
				++trailingSpacesCount;
			}
		}
		else {
			out << ' ' << ' ';
		}
	}

	for (int count{ 0 }; count < trailingSpacesCount; ++count) {
		out << ' ';
	}

	return out;
}


void Card::select() {
	m_isSelected = !m_isSelected;
}