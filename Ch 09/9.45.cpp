#include <iostream>
#include <string>
using namespace std;
void increase(string &name, const string &p, const string &l)
{
	name.insert(name.begin(), p.cbegin(), p.cend());
	name.append(l);
}
int main()
{
	string name, p, l;
	cin >> name >> p >> l;
	increase(name, p, l);
	cout << name << endl;
	return 0;
}