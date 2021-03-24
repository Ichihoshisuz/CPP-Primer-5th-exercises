#include <iostream>
using namespace std;
struct X
{
	X()
	{
		cout << "X ()" << endl;
	}
	X(const X& x)
	{
		cout << "X (const X& x)" << endl;
	}
	X operator=(const X& x)
	{
		cout << "X operator=(const X& x)" << endl;
		return *this;
	}
	~X()
	{
		cout << "~X ()" << endl;
	}
};