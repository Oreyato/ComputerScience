#include <iostream>
#include <string>
using namespace std;

// O(n^2) -bad- solution
bool isUniqueN2(string word) {
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

// O(n) solution
bool isUniqueN(string str) {
	// Return false if there is more than 128 characters (there is bound to be a double in this case)
	if (str.length() > 128) return false;

	bool alreadyExists[128];
	memset(alreadyExists, false, 128);

	for (int i = 0; i < str.length(); i++)
	{
		int v = str[i];

		if (alreadyExists[v]) {
			return false;
		}

		alreadyExists[v] = true;
	}

	return true;
}

int main() {
	string word;

	cout << "Enter a word: ";
	cin >> word;

	bool areLettersUnique;
	areLettersUnique = isUniqueN(word);
	if (areLettersUnique) {
		cout << "Yeh";
	}
	else {
		cout << "Oh...";
	}

	return 0;
}