#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
	string word;
	cin >> word;
	for (auto &a : word)
	{
		if (ispunct(a))
			a = '\0';
	}
	cout << word << endl;
	system("pause");
	return 0;
}