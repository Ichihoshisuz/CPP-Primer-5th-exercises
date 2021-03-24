#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	char a[80] = "ijwoqtqowtuioqwuto";
	char b[80] = "wirwiruwiruwiruiwuriwrwrwrwrw";
	char c[160];
	strcat_s(a, b);
	strcpy_s(c, a);
	cout << c << endl;
	system("pause");
	return 0;
}