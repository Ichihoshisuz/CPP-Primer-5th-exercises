#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class StrLenIs
{
public:
	StrLenIs(size_t i = 0) :len(i) {}
	//bool operator()(const string& str) const { return len == str.size(); }
	//14.39
	bool operator()(const string& str) const { return 1 <= str.size() && str.size() <= len; }
private:
	size_t len;
};

void count_string_size(const vector<string>& vs)
{
	StrLenIs sli(9);
	int c = count_if(vs.begin(), vs.end(), sli);
	cout <<"1 - 9: " << c << endl;
	cout << "10~ :" << vs.size() - c;
}

void count_string_size(const vector<string>& vs, int threshold)
{
	for (int i = 1; i <= threshold; ++i)
	{
		StrLenIs sli(i);
		int c = count_if(vs.begin(), vs.end(), sli);
		cout << i << ": " << c << endl;
	}
}