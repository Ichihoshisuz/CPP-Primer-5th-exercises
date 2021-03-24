#include <string>
#include <map>
#include <vector>
#include <set>
#include <sstream>
#include <iostream>
#include <fstream>
#include <memory>
#include <utility>
using namespace std;
class QueryResult;
class TextQuery
{
	friend QueryResult;
public:
	TextQuery() = default;
	explicit TextQuery(ifstream& is)
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

	shared_ptr <TextQuery> get_shared_ptr() const 
	{
		return make_shared<TextQuery>(*this);
	}
private:
	vector<string> line;
	shared_ptr <TextQuery> ptr_text = nullptr;
	map <string, set<int>>getword;
};

class QueryResult
{
public:
	QueryResult() = default;
	QueryResult(TextQuery& text):tqPtr(text.get_shared_ptr()){}
	void print(const string& word)
	{
		auto count = tqPtr->getword.count(word);
		for (auto p = tqPtr->getword.equal_range(word); p.first != p.second; ++p.first)
		{
			for (auto pos : p.first->second)
			{
				cout << pos << endl;
				cout << tqPtr->line[pos] << endl;
			}
		}
	}
private:
	shared_ptr<TextQuery> tqPtr = nullptr;
};