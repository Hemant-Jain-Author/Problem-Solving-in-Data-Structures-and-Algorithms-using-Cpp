#include "Rectangle.h"

Rectangle::Rectangle() : 
	Rectangle(1, 1)
{
}

Rectangle::Rectangle(double w, double l)
{
	width = w;
	length = l;
}

void Rectangle::setWidth(double w)
{
	width = w;
}

void Rectangle::setLength(double l)
{
	length = l;
}

double Rectangle::area()
{
	// Area = width * length
	return width * length;
}

double Rectangle::perimeter()
{
	// Perimeter = 2(width + length)
	return 2 * (width + length);
}