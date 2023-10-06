#include <iostream>
#include "Circle.h"
using namespace std;

void printCircles(Circle** circleArray, int numCircles);

int main()
{
	int howMany = 0;
	double radius = 0;

	cout << "how many circles do you wish to make?" << endl;
	cin >> howMany;

	Circle** circs = new Circle*[howMany];

	for (int i = 0; i < howMany; i++)
	{
		cout << "please enter a radius for circle " << i + 1 << endl;
		cin >> radius;
		circs[i] = new Circle(radius);
	}

	cout << endl;

	printCircles(circs, howMany);

	for (int i = 0; i < howMany; i++)
	{
		delete circs[i];
		circs[i] = nullptr;
	}

	delete[] circs;

	return 0;
}

void printCircles(Circle** circleArray, int numCircles)
{
	for (int i = 0; i < numCircles; i++)
	{
		cout << "Circle " << i + 1 << ":" << endl;
		cout << "\tRadius: " << circleArray[i]->getRadius() << endl;
		cout << "\tCircumfrence: " << circleArray[i]->circumference() << endl;
		cout << "\tArea: " << circleArray[i]->area() << endl;
		cout << endl;
	}
}