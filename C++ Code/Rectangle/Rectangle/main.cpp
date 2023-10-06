#include <iostream>
#include "Rectangle.h"
using namespace std;

int main() 
{
	const int ARR_SIZE = 3;
	Rectangle* recs[ARR_SIZE];
	recs[0] = new Rectangle(5, 3);
	recs[1] = new Rectangle(20, 40);
	recs[2] = new Rectangle(2, 10);

	for (int i = 0; i < ARR_SIZE; i++)
	{
		cout << "Rectangle " << i + 1 << endl;
		cout << "\tPerimeter: " << recs[i]->perimeter() << endl;
		cout << "\tArea: " << recs[i]->area() << endl;
		cout << endl;
	}
	
	for (int i = 0; i < ARR_SIZE; i++)
	{
		delete recs[i];
		recs[i] = nullptr;
	}
	return 0;
}