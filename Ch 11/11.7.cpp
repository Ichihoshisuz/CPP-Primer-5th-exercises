#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;
int main()
{
	map<string, vector<string>>family;
	string surname, forename;
	while (cin >> surname)
	{
		while (cin >> forename)
			family[surname].push_back(forename);
		cin.clear();
	}
	for (auto& c : family)
	{
		cout << "Surname: " << c.first << endl;
		cout << "Forename: ";
		for (auto& d : c.second)
			cout << d << " ";
		cout << endl;
	}
	return 0;


}