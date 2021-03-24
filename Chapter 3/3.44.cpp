/*
#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	using ffor = int (&)[4];
	using xfor = size_t;
	using zfor = int(*)[4];
	int a[3][4];
	srand((unsigned)time(NULL));
	for (auto &c : a)
	{
		for (auto &d : c)
			d = rand() % 100;
	}
	cout << endl;
	for (ffor c: a)
	{
		for (int &d : c)
			cout << d << " ";
	}
	cout << endl;
	for (xfor i = 0; i != 3; ++i)
	{
		for (xfor j = 0; j != 4; ++j)
			cout << a[i][j] << " ";
	}
	cout << endl;
	for (zfor p = a; p != end(a); ++p)
	{
		for (int *q = *p; q != end(*p); ++q)
			cout << *q << " ";
	}
	cout << endl;
	system("pause");
	return 0;

}
*/