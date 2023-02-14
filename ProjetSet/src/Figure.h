#pragma once

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

	int getID() { return m_ID; }
	Shape getShape() { return m_shape; }
	Color getColor() { return m_color; }
	Filling getFilling() { return m_filling; }
	int getNumber() { return m_number; }


};