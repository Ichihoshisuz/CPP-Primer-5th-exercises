#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	ifstream in("dictionary.txt");
	list<string> list;
	string word;
	while (in >> word)
		list.push_back(word);
	list.sort();
	list.unique();
	for (auto c : list)
		cout << c << endl;
	return 0;
}