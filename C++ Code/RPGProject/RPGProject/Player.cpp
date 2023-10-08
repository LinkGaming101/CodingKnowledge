#include "Player.h"

using namespace std;

Player::Player(string name, Race race, int hp, int mp)
{
	this->name = name;
	this->race = race;
	this->hp = hp;
	this->mp = mp;
}
string Player::getName() const noexcept
{
	return name;
}
Race Player::getRace() const noexcept
{
	return race;
}
string Player::whatRace() const noexcept
{
	switch (race)
	{
		case HUMAN:
			return "Human";
		case ELF:
			return "Elf";
		case DWARF:
			return "Dwarf";
		case ORC:
			return "Orc";
		case TROLL:
			return "Troll";
	}
}
int Player::getHitPoints() const noexcept
{
	return hp;
}
int Player::getMagicPoints() const noexcept
{
	return mp;
}
void Player::setName(string name)
{
	this->name = name;
}
void Player::setRace(Race race)
{
	this->race = race;
}
void Player::setHitPoints(int hp)
{
	this->hp = hp;
}
void Player::setMagicPoints(int mp)
{
	this->mp = mp;
}