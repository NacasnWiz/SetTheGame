#include "Figure.h"

Figure::Figure(Color color, Shape shape, Filling filling, int number) 
	: m_color{color}, m_shape{shape}, m_filling{filling}, m_number{number},
	m_ID{ color * 27 + shape * 9 + filling * 3 + number }
{
}

Figure::Figure(int ID)
	: m_ID{ ID }, m_number { ID % 3 }
{
	switch ((ID%81) / 27) {
	case 0:
		m_color = blue;
		break;
	case 1:
		m_color = red;
		break;
	case 2:
		m_color = green;
		break;
	}

	switch ((ID%27) / 9) {
	case 0:
		m_shape = triangle;
		break;
	case 1:
		m_shape = square;
		break;
	case 2:
		m_shape = circle;
		break;
	}

	switch ((ID%9) / 3) {
	case 0:
		m_filling = blank;
		break;
	case 1:
		m_filling = hatched;
		break;
	case 2:
		m_filling = full;
		break;
	}
}