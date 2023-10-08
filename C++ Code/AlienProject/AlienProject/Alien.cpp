#include "Alien.h"

#include <cstdlib>
#include <ctime>
using namespace std;

Alien::Alien(int weight, int height, char gender)
{
	this->weight = weight;
	this->height = height;
	this->gender = gender;
}
int Alien::getWeight() const
{
	return weight;
}
int Alien::getHeight() const
{
	return height;
}
char Alien::getGender() const
{
	return gender;
}
int Alien::getPrestige() const
{
	int genderScore;

	if (gender == 'F')
	{
		genderScore = 3;
	}
	else if (gender == 'M')
	{
		genderScore = 2;
	}

	return height * weight * genderScore;
}

//operators
bool Alien::operator==(const Alien& other) const
{
	return getPrestige() == other.getPrestige();
}
bool Alien::operator!=(const Alien& other) const
{
	return getPrestige() != other.getPrestige();
}
bool Alien::operator >(const Alien& other) const
{
	return getPrestige() > other.getPrestige();
}
bool Alien::operator>=(const Alien& other) const
{
	return getPrestige() >= other.getPrestige();
}
bool Alien::operator <(const Alien& other) const
{
	return getPrestige() < other.getPrestige();
}
bool Alien::operator<=(const Alien& other) const
{
	return getPrestige() <= other.getPrestige();
}
void Alien::operator=(const Alien& other)
{
	weight = other.weight;
	height = other.height;
	gender = other.gender;
}
Alien Alien::operator+(const Alien& other) const
{
	srand(time(nullptr));

	int randNum = rand() % 10;

	char newGender;
	int newHeight = (height + other.height) / 2;
	int newWeight = (weight + other.weight) / 2;

	if (randNum < 4)
	{
		newGender = 'F';
	}
	else
	{
		newGender = 'M';
	}

	return Alien(newWeight, newHeight, newGender);
}