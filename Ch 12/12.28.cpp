#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <memory>
using namespace std;
void Create_getword(ifstream& is,vector<string>& line,map<string,set<int>>& getword)
{
	int i = 0;
	string word;
	while (getline(is, word))
	{
		line.push_back(word);
		for (auto c = word.begin(), d = c; c != word.cend(); ++c)
		{
			if (*c == ' ' && c == d)
				++c;
			else if (*c == ' ')
			{
				string gword(d, c);
				if (getword.find(gword) == getword.cend())
				{
					set<int> number{ i };
					getword.insert(make_pair(gword, number));
				}
				else
				{
					getword[gword].insert(i);
				}
				d = c + 1;
			}
		}
		++i;
	}
}
void print(const string& word, vector<string>& line, map<string, set<int>>& getword)
{
	auto count = getword.count(word);
	for (auto p = getword.equal_range(word); p.first != p.second; ++p.first)
	{
		for (auto pos : p.first->second)
		{
			cout << pos << endl;
			cout << line[pos] << endl;
		}
	}
}
int main()
{
	vector<string> line;
	map<string, set<int>> getword;
	ifstream in("News.txt");
	Create_getword(in, line, getword);
	string s;
	while (cin >> s && s != "q")
	{
		print(s, line, getword);
	}
	return 0;
}