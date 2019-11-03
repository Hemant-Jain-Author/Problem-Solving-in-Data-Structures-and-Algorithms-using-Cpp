#include <iostream>
#include <string>
#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"


int main()
{
	double width = 2, length = 3;
	Shape *rectangle = new Rectangle(width, length);
	std::cout << "Rectangle width: " << width << " and length: " << length << " Area: " << rectangle->area() << " Perimeter: " << rectangle->perimeter() << std::endl;

	double radius = 10;
	Shape *circle = new Circle(radius);
	std::cout << "Circle radius: " << radius << " Area: " << circle->area() << " Perimeter: " << circle->perimeter() << std::endl;
	return 0;
}