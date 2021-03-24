#include <iostream>
#include <list>
#include <string>
using namespace std;
int main()
{
	string word;
	list<string> sw;
	while (cin >> word)
		sw.push_back(word);
	for (auto c : sw)
		cout << c << endl;
	return 0;
}