#include <iostream>
using namespace std;
int main()
{
	unsigned int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, spaceCnt = 0, tCnt = 0, nCnt = 0;
	char ch;
	while (cin.get(ch))
	{
		switch (ch)
		{
		case 'a':
		case 'A':++aCnt; break;
		case 'e':
		case 'E':++eCnt; break;
		case 'i':
		case 'I':++iCnt; break;
		case 'o':
		case 'O':++oCnt; break;
		case 'u':
		case 'U':++uCnt; break;
		case ' ':++spaceCnt; break;
		case '\t':++tCnt; break;
		case '\n':++nCnt; break;
		default:break;
		}
	}
	cout << aCnt << " " << eCnt << " " << iCnt << " " << oCnt << " " << uCnt << " " << spaceCnt << " " << tCnt << " " <<nCnt<< endl;
	system("pause");
	return 0;
}