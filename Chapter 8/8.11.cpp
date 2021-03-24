#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "PersonInfo.h"
using namespace std;
int main()
{
	string line, word;
	vector<PersonInfo> people;
	istringstream record;
	while (getline(cin, line))
	{
		if (record.eof())
		{
			cout << "ÖÃÎ»" << endl;
			break;
		}
		record.str(line);
		PersonInfo info;
		record >> info.name;
		while (record >> word)
			info.phones.push_back(word);
		people.push_back(info);
	}
	for (auto c : people)
	{
		cout << c.name << " ";
		for (auto d : c.phones)
			cout << d << " ";
		cout << endl;
	}
	system("pause");
	return 0;
}