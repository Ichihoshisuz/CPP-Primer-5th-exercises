#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <memory>
#include <map>
#include <set>
#include <iterator>
#include "StrBlob.h"
using namespace std;

class QueryResult
{
	friend ostream& print(ostream& os, const QueryResult& Qr);
public:
	QueryResult(shared_ptr<vector<string>> articles, shared_ptr<set<int>> n, string w)
		:lines(articles), numbers(n), word(w) {};
private:
	StrBlob lines;
	shared_ptr<set<int>> numbers;
	string word;
};

class TextQuery
{
public:
	TextQuery() = default;
	TextQuery(ifstream& is):text()
	{
		string line;
		while (getline(is, line))
		{
			text.push_back(line);
			istringstream c(line);
			string word;
			set<int> number{ 0 };
			while (c >> word)
			{
				if (lines.find(word) == lines.cend())
				{
					lines.insert({ word, make_shared<set<int>>(number) });
				}
				else
				{
					lines[word]->insert(text.size() - 1);
				}
			}
		}
	}
	QueryResult query(const string & word) const
	{
		auto locate = lines.find(word);
		//static shared_ptr<set<int>>nodata = make_shared<set<int>>(set<int>());
		if (locate == lines.cend())
			return QueryResult(text.data, nullptr, word);
		else
			return QueryResult(text.data, locate->second, word);
	}
private:
	StrBlob text;
	map<string, shared_ptr<set<int>>> lines;
};


ostream& print(ostream & os, const QueryResult & Qr)
{
	if (Qr.numbers != nullptr)
	{
		auto iter = Qr.lines.begin();
		os << "单词" << Qr.word << "出现了" << Qr.numbers->size() << "次" << endl;
		for (auto& p : *(Qr.numbers))
		{ 
			cout << '\t' << p << " " << iter.deref(p) << endl;
		}
	}
	else
	{
		cout << "单词" << Qr.word << "并不在文本中" << endl;
	}
	return os;
}