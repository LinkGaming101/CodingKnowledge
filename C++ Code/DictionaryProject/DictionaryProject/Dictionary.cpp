#include "Dictionary.h"
#include <iostream>
using namespace std;

void Dictionary::addDefinition(string word, string definition)
{
	auto it = dictionary.find(word);

	if (it != dictionary.end())
	{
		// already in
		it->second = definition;
	}
	else
	{
		// new word
		dictionary[word] = definition;
	}
}
string Dictionary::getDefinition(string word) const
{
	auto it = dictionary.find(word);
	string result = "";

	if (it != dictionary.end())
	{
		result = it->second;
	}
	else
	{
		result = "NOT FOUND";
	}

	return result;
}
void Dictionary::printAll()
{
	for (auto element : dictionary)
	{
		cout << element.first << ":" 
			<< "\n\tDefinition: " << element.second << endl;
	}
	cout << endl;
}