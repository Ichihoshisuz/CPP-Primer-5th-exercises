#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> vi{ 1,2,3,4,5,6,7,8,9,10 };
	vector<int>::const_iterator beg = vi.cbegin();
	vector<int>::const_iterator end = vi.cend();
	auto p = beg;
	int i;
	cin >> i;
	for (; p != end; ++p)
	{
		if (i == *p)
		{
			cout << "查找到给定的值" <<" "<< p-beg << endl;
			break;
		}
	}
	if (p == end)
		cout << "vi中没有给定的值" <<" "<<p-beg<< endl;
	system("pause");
	return 0;
}