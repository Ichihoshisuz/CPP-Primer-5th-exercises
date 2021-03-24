#include <iostream>
using namespace std;
int main()
{
	int ffCnt = 0, flCnt = 0, fiCnt = 0;
	char ch;
	while (cin >> ch)
	{
		if (ch == 'f')
		{
			cin >> ch;
			if (ch == 'f')
				++ffCnt;
			else if (ch == 'l')
				++flCnt;
			else if (ch == 'i')
				++fiCnt;
		}
	}
	cout << ffCnt << " " << flCnt << " " << fiCnt << endl;
	system("pause");
	return 0;
}