#include <iostream>
#include <string>
using namespace std;
int main()
{
	string a, b;
	cin >> a;
	b = a;
	while (cin >> a)
		b = b + '\0' + a;
	cout << b << endl;
	system("pause");
	return 0;
}