#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <string>
using namespace std;
int main()
{
	map<string, list<int>> word_line;
	ifstream in("dictionary.txt");
	string line;
	int i = 1;
	while (getline(in, line))
	{
		auto p = line.cbegin();
		for (auto start = line.cbegin(); start != line.cend(); ++start)
		{
			if (*start == ' ')
			{
				word_line[string(p, start)].push_back(i);
				p = start + 1;
			}
		}
		word_line[string(p, line.cend())].push_back(i);
		++i;
	}
	for (auto& c : word_line)
	{
		cout << c.first << "的出现的行数为:";
		for (auto d : c.second)
			cout << d << " ";
		cout << endl;
	}
	return 0;
}