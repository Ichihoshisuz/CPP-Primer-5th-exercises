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
			cout << "���ҵ�������ֵ" << i << endl;
			break;
		}
	}
	if (beg == end)
		cout << "vi��û�и�����ֵ" << endl;
	return 0;
}