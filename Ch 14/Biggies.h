#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class GreaterCompare
{
public:
	GreaterCompare(size_t n) :len(n) {};
	bool operator()(const string& str) const { return len <= str.size(); }
private:
	size_t len;
};

void elimDpus(vector<string>& vstr)
{
	sort(vstr.begin(), vstr.end());
	auto end_unique = unique(vstr.begin(), vstr.end());
	vstr.erase(end_unique, vstr.end());
	return;
}

void biggies(vector<string>& vstr, vector<string>::size_type sz)
{
	elimDpus(vstr);
	stable_sort(vstr.begin(), vstr.end(),
		[](const string& a, const string& b)
		{
			return a.size() < b.size();
		});
	GreaterCompare gc(sz);
	auto pstr = find_if(vstr.begin(), vstr.end(), gc);
	for (pstr; pstr != vstr.end(); ++pstr) {
		cout << *pstr << " ";
	}
	cout << endl;
}