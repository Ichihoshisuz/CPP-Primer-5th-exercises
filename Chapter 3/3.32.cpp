#include <iostream>
#include <cstddef>
using namespace std;
int main()
{
	int a[10] = {}, a1[10] = {};
	for (size_t b = 0; b != 10; ++b)
	{
		a[b] = b;
		a1[b] = a[b];
	}
	cout << endl;
	system("pause");
	return 0;

}