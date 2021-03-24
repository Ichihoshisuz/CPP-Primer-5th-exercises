#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <string>
using namespace std;
void transform_rule(ifstream& input,unordered_map<string, string>& rule)
{
	string key;
	string line;
	string confirm;
	while (input >> key && getline(input, line))
	{
		if (rule.find(key) != rule.cend())
		{
			cout << "�Ƿ��滻ת���������밴y����Y���س�" << endl;
			cin >> confirm;
			if (confirm == "y" || confirm == "Y")
			{
				if (line.size() > 1)
				{
					string value(line.substr(1));
					rule.erase(key);
					rule.insert({ key,value });
				}
				else
					cout << key << "������ת������" << endl;
			}
		}
		if (line.size() > 1)
		{
			string value(line.substr(1));
			rule.insert({ key,value });
		}
		else
			cout << key << "������ת������" << endl;
	}
}
void transform_display(ifstream& input, ifstream& words_input)
{
	unordered_map<string, string> rule;
	transform_rule(input, rule);
	string line;
	while (getline(words_input, line))
	{
		istringstream words(line);
		string word;
		while (words >> word)
		{
			auto iter = rule.find(word);
			if (iter != rule.cend())
				cout << iter->second;
			else
				cout << word;
			cout << " ";
		}
		cout << endl;
	}
}
int main()
{
	ifstream input("rule.txt");
	ifstream words_input("Text.txt");
	transform_display(input, words_input);
	return 0;
}