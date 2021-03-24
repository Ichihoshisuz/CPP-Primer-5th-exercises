#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> vi{ 1,2,3,4,5,6,7,8,9,10 };
	vector<int>::const_iterator beg = vi.cbegin();
	vector<int>::const_iterator end = vi.cend();
	int i;
	cin >> i;
	for (; beg != end; ++beg)
	{
		if (i == *beg)
		{
			cout << "查找到给定的值" << i << endl;
			break;
		}
	}
	if (beg == end)
		cout << "vi中没有给定的值" << endl;
	return 0;
}