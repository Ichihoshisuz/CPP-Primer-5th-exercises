#include <iostream>
using namespace std;
int main()
{
	int i;
	cin >> i;
	auto f=[&i]()mutable->bool{
		while (i != 0)
			--i;
		return i == 0;
	};
	if (f())
		cout << "�ѵݼ�Ϊ0" << endl;
	else
		cout << "�ݼ�ʧ��" << endl;
	return 0;
}