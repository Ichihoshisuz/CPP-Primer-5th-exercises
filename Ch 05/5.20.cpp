#include <iostream>
#include <string>
using namespace std;
int main()
{
	bool bl = false;
	string str1, str2;
	while (cin >> str1)
	{
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
		cout << "û���ظ��ĵ���" << endl;
	system("pause");
	return 0;
}