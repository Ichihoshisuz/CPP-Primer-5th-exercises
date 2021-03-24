#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int i = 0,j,k;
	vector<int> v1 = { 1,2,3,4,5,6,7,8,9 };
	vector<int> v2 = { 1,2,3,4,5,6,7,8 };
	auto v1beg = v1.cbegin();
	auto v1end = v1.cend();
	auto v2beg = v2.cbegin();
	auto v2end = v2.cend();
	for (; v1beg!=v1end&&v2beg!=v2end; ++v1beg, ++v2beg)
	{
		if (*v1beg != *v2beg)
			break;
	}
	if (v1beg == v1end)
		cout << "v1为前缀" << endl;
	else if (v2beg == v2end)
		cout << "v2为前缀" << endl;
	else
		cout << "不为前缀" << endl;
	system("pause");
	return 0;
}