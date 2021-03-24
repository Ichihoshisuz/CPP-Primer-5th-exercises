#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>
using namespace std;
using namespace placeholders;
bool more_sz(const string &s, string::size_type sz)
{
	return s.size() > sz;
}
void check_size(vector<string> &vi, string::size_type sz)
{
	auto g = bind(more_sz, _1, sz);
	bool a=g("sdsd");
	if (a)
		cout << "yes" << endl;
	auto p = find_if(vi.begin(), vi.end(),g);
	if (p == vi.end())
		cout << "没有找到给定的值" << endl;
	else
		cout << "给定的值为：" << *p << endl;
	return;
}
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
	check_size(vstr, sz);
	cout << endl;
}
int main()
{
	ifstream in("dictionary.txt");
	vector<string> vstr;
	string word;
	while (in >> word)
		vstr.push_back(word);
	biggies(vstr, 6);
	return 0;
}