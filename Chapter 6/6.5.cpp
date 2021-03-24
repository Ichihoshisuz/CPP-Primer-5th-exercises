#include <iostream>
using namespace std;
int abs(int x)
{
	if (x < 0)
		x = -x;
	return x;
}
int main()
{
	int a;
	cin >> a;
	a = abs(a);
	cout << a << endl;
	system("pause");
	return 0;
}