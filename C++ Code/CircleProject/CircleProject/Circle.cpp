#define _USE_MATH_DEFINES
#include "Circle.h"
#include <math.h>
#include <cmath>
using namespace std;

Circle::Circle()
{
	this->radius = 1;
}
Circle::Circle(double radius)
{
	this->radius = radius;
}
double Circle::getRadius() const
{
	return radius;
}
void Circle::setRadius(double radius)
{
	this->radius = radius;
}
double Circle::circumference() const
{
	return 2 * M_PI * radius;
}
double Circle::area() const
{
	return M_PI * pow(radius, 2);
}