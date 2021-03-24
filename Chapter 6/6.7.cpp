#include <iostream>
using namespace std;
int func(int a)
{
	static int x = a;
	return ++x;
}
int main()
{
	int a, b;
	cin >> a;
	for (int i = 0; i != 10; ++i)
	{
		b = func(a);
		cout << b << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}