
#include "Shape.h"

class Rectangle : public Shape
{

private:
	double width = 0, length = 0;

public:
	Rectangle();

	Rectangle(double w, double l);

	virtual void setWidth(double w);

	virtual void setLength(double l);

	virtual double area() override;

	virtual double perimeter() override;
};
