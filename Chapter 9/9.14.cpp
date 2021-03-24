#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;
int main()
{
	list<const char*> lc={ "a","b","c","d","e" };
	vector<string> vs;
	auto lcb = lc.begin();
	auto lce = lc.end();
	vs.assign(lcb, lce);
	for (auto c : vs)
	{
		cout << c<< endl;
	}
	return 0;
}