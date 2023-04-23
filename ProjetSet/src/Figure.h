#pragma once
#include "Includes.h"

enum Color {
	blue = 0,
	red = 1,
	green = 2,
};

enum Shape {
	triangle = 0,
	square = 1,
	circle = 2,
};

enum Filling {
	blank = 0,
	hatched = 1,
	full = 2,
};

class Figure {
private:
	Color m_color;
	Shape m_shape;
	Filling m_filling;
	int m_number;
	int m_ID;

public:

	Figure(Color color, Shape shape, Filling filling, int number);
	Figure(int ID);

	int getID() const { return m_ID; }
	Shape getShape() const { return m_shape; }
	Color getColor() const { return m_color; }
	Filling getFilling() const { return m_filling; }
	int getNumber() const { return m_number; }

	friend std::ostream& operator<<(std::ostream& out, const Figure& figure);
};


class Card : public Figure {
private:
	bool m_isSelected;

public:
	Card(Color color, Shape shape, Filling filling, int number) :
		m_isSelected{ false }, Figure(color, shape, filling, number)
	{
	}

	Card(int ID) :
		m_isSelected{ false }, Figure(ID)
	{
	}


	void select();
};