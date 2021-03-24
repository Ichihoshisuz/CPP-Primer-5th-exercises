/*
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
int main()
{
	string word;
	vector<string> vWord;
	while (cin >> word)
	{
		vWord.push_back(word);
		for (auto &a : vWord)
		{
			for (auto &b : a)
				b=toupper(b);
		}
	}
	for (auto c : vWord)
		cout << c << endl;
	system("pause");
	return 0;
}
*/