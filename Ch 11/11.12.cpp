#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;
int main()
{
	vector<pair<string, int>> what;
	pair<string, int> p;
	while (cin >> p.first >> p.second)
		what.push_back(p);
	for (auto& c : what)
		cout << c.first << " " << c.second << endl;
	return 0;
}