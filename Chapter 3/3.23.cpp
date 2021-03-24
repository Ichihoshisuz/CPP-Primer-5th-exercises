#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int>v1{10, 12, 23, 2, 4, 42, 5, 54, 6, 565};
	for (auto i = v1.begin(); i != v1.cend(); ++i)
		*i = *i * 2;
	for (auto a : v1)
		cout << a << " ";
	cout << endl;
	system("pause");
	return 0;
}