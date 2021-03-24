#include <iostream>
#include <string>
using namespace std;
int main()
{
	string word1, word2;
	int i = 1;
	cin >> word1;
	while (cin >> word2)
	{
		if (word1 == word2)
			++i;
		else
		{
			cout << word1 << " " << i << endl;
			i = 1;
			word1 = word2;
		}
	}
	cout << word1 << " " << i << endl;
	system("pause");
	return 0;
}