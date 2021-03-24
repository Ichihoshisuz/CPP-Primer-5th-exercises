#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
void elimDpus(vector<string> &vstr)
{
	sort(vstr.begin(), vstr.end());
	auto end_unique = unique(vstr.begin(), vstr.end());
	vstr.erase(end_unique, vstr.end());
	return;
}
void biggies(vector<string> &vstr, vector<string>::size_type sz)
{
	elimDpus(vstr);
	stable_sort(vstr.begin(), vstr.end(),
		[](const string &a, const string &b)
	{
		return a.size() < b.size();
	});
	auto pstr=find_if(vstr.begin(), vstr.end(), [sz](const string &s) {
		return s.size() >= sz;
	});
	for (pstr; pstr != vstr.end(); ++pstr) {
		cout << *pstr << " ";
	}
	cout << endl;
}
int main()
{
	vector<string> vstr;
	string word;
	while (cin >> word)
		vstr.push_back(word);
	biggies(vstr, 6);
	return 0;
}