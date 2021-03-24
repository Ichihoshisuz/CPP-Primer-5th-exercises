#include <vector>
#include <string>
#include <map>
#include <utility>
#include <iostream>
using namespace std;
int main()
{
	map<string, vector<pair<string,string>>> family;
	string surname, forename, birthday;
	while (cin >> surname)
	{
		while (cin >> forename>>birthday)
			family[surname].push_back(pair<string, string>{forename,birthday});
		cin.clear();
	}
	for (auto& c : family)
	{
		cout << "Surname: " << c.first << endl;
		cout << "Forename: ";
		for (auto& d : c.second)
			cout << d.first << " Birthday:" << d.second;
		cout << endl;
	}
	return 0;


}