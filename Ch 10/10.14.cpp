#include <iostream>
using namespace std;
int main()
{
	auto f=[](const int &a, const int &b)->int
	{
		int sum = a + b;
		return sum;
	};
	int a, b;
	cin >> a >> b;
	cout << f(a, b) << endl;
	return 0;
}