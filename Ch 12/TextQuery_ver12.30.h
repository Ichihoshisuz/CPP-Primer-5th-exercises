#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <memory>
#include <map>
#include <set>
using namespace std;

class QueryResult
{
	friend ostream& print(ostream& os, const QueryResult& Qr);
public:
	QueryResult(shared_ptr<vector<string>> articles, shared_ptr<set<int>> n, string w)
		:lines(articles), numbers(n), word(w) {};

	set<int>::iterator begin()
	{
		return numbers->begin();
	}
	set<int>::iterator end()
	{
		return numbers->end();
	}
	shared_ptr<vector<string>> get_file()
	{
		return lines;
	}
private:
	shared_ptr<vector<string>> lines;
	shared_ptr<set<int>> numbers;
	string word;
};

class TextQuery
{
public:
	TextQuery() = default;
	TextQuery(ifstream& is)
	{
		string line;
		text = make_shared<vector<string>>();
		while (getline(is,line))
		{
			text->push_back(line);
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
					lines[word]->insert(text->size() - 1);
				}
			}
		}
	}
	QueryResult query(const string& word) const
	{
		auto locate = lines.find(word);
		//static shared_ptr<set<int>>nodata = make_shared<set<int>>(set<int>());
		if (locate==lines.cend())
			return QueryResult(text, nullptr, word);
		else
			return QueryResult(text, locate->second, word);
	}
private:
	shared_ptr<vector<string>> text;
	map<string, shared_ptr<set<int>>> lines;
};


ostream& print(ostream& os, const QueryResult& Qr)
{
	if (Qr.numbers != nullptr)
	{
		os << "单词" << Qr.word << "出现了" << Qr.numbers->size() << "次" << endl;
		for (auto& p : *(Qr.numbers))
			cout << '\t' << p << " " << (*(Qr.lines->begin() + p)) << endl;
	}
	else
	{
		cout << "单词" << Qr.word << "并不在文本中" << endl;
	}
	return os;
}