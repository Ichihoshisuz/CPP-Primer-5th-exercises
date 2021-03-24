#include <iostream>
#include <string>
using namespace std;
int main()
{
	do
	{
		string str1, str2;
		cout << "输入两端字符" << endl;
		cin >> str1 >> str2;
		if (str1.size()< str2.size())
			cout << str1 << endl;
		else if (str2.size() < str1.size())
			cout << str2 << endl;
		else if(str2.size()==str1.size())
			cout << "两字符长度相等" << endl;
	} while (cin);
	system("pause");
	return 0;
}