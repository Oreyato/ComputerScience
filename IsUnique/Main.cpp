#include <iostream>
#include <string>
using namespace std;

bool isUnique(string word) {
	for (int i = 0; i < word.length(); i++)
	{
		for (int j = 1; j < word.length(); j++)
		{
			if (i == j) {
				continue;
			} else if (word[i] == word[j]) {
				return false;
			}
		}
	}
	
	return true;
}


int main() {
	string word;

	cout << "Enter a word: ";
	cin >> word;

	bool areLettersUnique;
	areLettersUnique = isUnique(word);
	if (areLettersUnique) {
		cout << "Yeh";
	}
	else {
		cout << "Oh...";
	}

	return 0;
}