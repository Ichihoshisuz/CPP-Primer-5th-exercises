#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <memory>
#include <map>
#include <set>
#include <iterator>
#include "13.40 StrVec.h"

using namespace std;

class QueryResult
{
	friend ostream& print(ostream& os, const QueryResult& Qr);
public:
	QueryResult(shared_ptr<StrVec> articles, shared_ptr<set<int>> n, string w)
		:lines(articles), numbers(n), word(w) {};

	set<int>::iterator begin()
	{
		return numbers->begin();
	}
	set<int>::iterator end()
	{
		return numbers->end();
	}
	shared_ptr<StrVec> get_file()
	{
		return lines;
	}
private:
	shared_ptr<StrVec> lines;
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
		text = make_shared<StrVec>();
		while (getline(is, line))
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
		if (locate == lines.cend())
			return QueryResult(text, nullptr, word);
		else
			return QueryResult(text, locate->second, word);
	}
private:
	shared_ptr<StrVec> text;
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

void runQueries(ifstream& infile)
{
	TextQuery tq(infile);
	while (true)
	{
		cout << "enter word to look for, or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q")
			break;
		print(cout, tq.query(s)) << endl;
	}
}