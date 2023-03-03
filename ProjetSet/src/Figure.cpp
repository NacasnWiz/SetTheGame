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