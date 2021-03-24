#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;
int main()
{
	map<string, size_t> count;
	string word;
	ifstream in("dictionary.txt");
	while (in >> word)
	{
		auto ret = count.insert({ word,1 });
		if (!ret.second)
			++ret.first->second;
	}
	for (auto& c : count)
		cout << c.first << "������" << c.second << "��" << endl;
	return 0;
}