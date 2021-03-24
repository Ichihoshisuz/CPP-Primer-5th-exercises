#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	vector<string> vWord;
	string word;
	while (getline(cin, word))
		vWord.push_back(word);
	for (auto a : vWord)
		cout << a << endl;
	system("pause");
	return 0;

}