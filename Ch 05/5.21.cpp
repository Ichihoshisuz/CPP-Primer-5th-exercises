#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
	bool bl = false;
	string str1, str2;
	while (cin >> str1)
	{
		if (!isupper(str1[0]))
			continue;
		if (str1 == str2)
		{
			bl = true;
			break;
		}
		else
			str2 = str1;
	}
	if (bl)
		cout << str1 << endl;
	else
		cout << "没有重复的单词" << endl;
	system("pause");
	return 0;
}