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
	for (auto &c : vstr)
		cout << c << endl;
	return;
}
int main()
{
	vector<string> vstr;
	string word;
	while (cin >> word)
		vstr.push_back(word);
	elimDpus(vstr);
	return 0;
}