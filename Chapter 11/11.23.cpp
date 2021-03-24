#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;
int main()
{
	multimap<string, string>family;
	string surname, forename;
	while (cin >> surname)
	{
		while (cin >> forename)
			family.insert({ surname,forename });
		cin.clear();
	}
	for (auto& c : family)
	{
		cout << "Surname: " << c.first << endl;
		cout << "Forename: " << c.second << endl;
	}
	return 0;


}