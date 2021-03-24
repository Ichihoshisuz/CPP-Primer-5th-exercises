#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	ifstream in("dictionary.txt");
	string word;
	vector<string> words;
	list<string> lstw;
	while (in >> word)
		words.push_back(word);
	sort(words.begin(), words.end());
	for (auto c : words)
		cout << c << " ";
	cout << endl;
	unique_copy(words.cbegin(), words.cend(),back_inserter(lstw));
	for (auto c : lstw)
		cout << c << " ";
	cout << endl;
	return 0;
}