
#include "Shape.h"
#include <cmath>

class Circle : public Shape
{
private:
	double radius = 0;

public:
	Circle();

	Circle(double r);

	virtual void setRadius(double r);

	virtual double area() override;

	virtual double perimeter() override;
};
