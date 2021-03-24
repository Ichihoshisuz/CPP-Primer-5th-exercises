/*
#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	int a[3][4];
	srand((unsigned)time(NULL));
	for (auto &c : a)
	{
		for (auto &d : c)
			d = rand() % 100;
	}
	cout << endl;
	for (int (&c)[4]: a)
	{
		for (int &d:c)
			cout << d << " ";
	}
	cout << endl;
	for (size_t i = 0; i != 3; ++i)
	{
		for (size_t j = 0; j != 4; ++j)
			cout << a[i][j] << " ";
	}
	cout << endl;
	for (int(*p)[4] = a; p != end(a); ++p)
	{
		for (int *q = *p; q != end(*p); ++q)
			cout << *q << " ";
	}
	cout << endl;
	system("pause");
	return 0;

}
*/