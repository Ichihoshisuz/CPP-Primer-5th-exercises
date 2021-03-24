#include <iostream>
using namespace std;
int main()
{
	double i, j;
	cin >> i >> j;
	try 
	{
		if (j == 0)
			throw runtime_error("除数不能为0");
		cout << i / j << endl;
	}
	catch (runtime_error err)
	{
		cout << err.what() << endl;
	}
	system("pause");
	return 0;
}