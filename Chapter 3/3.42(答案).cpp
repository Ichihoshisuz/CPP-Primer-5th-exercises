#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{
	const int sz = 10;
	vector<int> vInt;
	srand((unsigned)time(NULL));
	cout << "vector����������ǣ�" << endl;
	for (int i = 0; i != sz; ++i)
	{
		vInt.push_back(rand() % 100);
		cout << vInt[i] << " ";
	}
	cout << endl;
	auto it = vInt.cbegin();
	int a[10];
	cout << "�����������" << endl;
	for (auto &val:a)
	{
		val = *it;
		cout << val << " ";
		++it;
	}
	cout << endl;
	system("pause");
	return 0;
}