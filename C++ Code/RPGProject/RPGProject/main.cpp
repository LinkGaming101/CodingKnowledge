#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "Warrior.h"
#include "Priest.h"
#include "Mage.h"

using namespace std;

void printMainMenu();
void printRaceMenu();

Player* createPlayer(string playerName, int typeNum, int raceNum);
void doCleanup(vector<Player*> playerList);
Race getRace(int raceNum);

void printAll(vector<Player*> playerList);
 
int main()
{
	/*
		starts off at class selection
		next is naming the character
		then race selection

		repeat until you have 4 party members then print out their attack
		end the program
	*/

	int choice;
	int raceNum;
	string playerName;

	vector<Player*> playerList;

	printMainMenu();
	cin >> choice;
	cin.get(); //consume new line

	while (choice != 0)
	{
		cout << "Please name this character!" << endl;
		getline(cin, playerName);

		printRaceMenu();
		cin >> raceNum;
		cin.get();

		Player* tempPlayer = createPlayer(playerName, choice, raceNum);
		playerList.push_back(tempPlayer);

		printMainMenu();
		cin >> choice;
		cin.get();
	}

	printAll(playerList);

	doCleanup(playerList);

	return 0;
}

void printMainMenu()
{
	cout << endl;
	cout << "Please choose your class!" << endl;
	cout << "\t1 - Warrior" << endl;
	cout << "\t2 - Priest" << endl;
	cout << "\t3 - Mage" << endl;
	cout << "\t0 - finish character creation" << endl;
}
void printRaceMenu()
{
	cout << endl;
	cout << "Please choose your race!" << endl;
	cout << "\t1 - Human" << endl;
	cout << "\t2 - Elf" << endl;
	cout << "\t3 - Dwarf" << endl;
	cout << "\t4 - Orc" << endl;
	cout << "\t5 - Troll" << endl;
}

Player* createPlayer(string playerName, int typeNum, int raceNum)
{
	Race playerRace = getRace(raceNum);
	Player* tempPlayer = nullptr;

	switch (typeNum)
	{
		case 1:
			tempPlayer = new Warrior(playerName, playerRace);
			break;
		case 2:
			tempPlayer = new Priest(playerName, playerRace);
			break;
		case 3:
			tempPlayer = new Mage(playerName, playerRace);
			break;
	}

	return tempPlayer;
}
void doCleanup(vector<Player*> playerList)
{
	for (Player* player : playerList)
	{
		delete player;
	}
	playerList.clear();
}
Race getRace(int raceNum)
{
	Race race;

	switch (raceNum)
	{
		case 1:
			race = HUMAN;
			break;
		case 2:
			race = ELF;
			break;
		case 3:
			race = DWARF;
			break;
		case 4:
			race = ORC;
			break;
		case 5:
			race = TROLL;
			break;
	}

	return race;
}

void printAll(vector<Player*> playerList)
{
	for (Player* player : playerList)
	{
		cout << player->getName() << ": \n\tRace: "
			<< player->whatRace() << "\n\tClass Attack: "
			<< player->attack() << endl;
	}
}