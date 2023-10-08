#include <iostream>
#include "Dictionary.h"

using namespace std;

void mainMenu();
void addWord(Dictionary& dictionary);
void printDef(const Dictionary dictionary);

int main()
{
	int input = 0;
	Dictionary dictionary;

	cout << "Welcome to the Library of Alexandria!" << endl;

	mainMenu();
	cin >> input;
	cin.get();

	while (input != 4)
	{
		if (input == 1)
		{
			addWord(dictionary);
		}
		else if (input == 2)
		{
			printDef(dictionary);
		}
		else if (input == 3)
		{
			cout << "Printing all definitions:" << endl;
			dictionary.printAll();
			cout << endl;
		}

		cout << endl;
		mainMenu();
		cin >> input;
		cin.get();
	}

	return 0;
}

void mainMenu()
{
	cout << "Would you like to: "
		<< "\n\t1: input a new word"
		<< "\n\t2: print previous words and definitions"
		<< "\n\t3: print all inputed definitions"
		<< "\n\t4: exit" << endl;
}

void addWord(Dictionary& dictionary)
{
	string tempWord;
	string tempDef;

	cout << "Enter the new word" << endl;
	getline(cin, tempWord);

	cout << "Enter the definition for " << tempWord << endl;
	getline(cin, tempDef);

	dictionary.addDefinition(tempWord, tempDef);
}

void printDef(const Dictionary dictionary)
{
	string tempWord;

	cout << "Enter in the word you want the definition for" << endl;
	getline(cin, tempWord);

	cout << dictionary.getDefinition(tempWord) << endl;
	cout << endl;
}