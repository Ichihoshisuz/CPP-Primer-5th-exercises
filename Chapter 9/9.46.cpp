#include <iostream>
#include <string>
using namespace std;
void increase(string &name, const string &p, const string &l)
{
	name.insert(0, p, 0, p.size());
	name.insert(name.size(), l, 0, l.size());
}
int main()
{
	string name, p, l;
	cin >> name >> p >> l;
	increase(name, p, l);
	cout << name << endl;
	return 0;
}