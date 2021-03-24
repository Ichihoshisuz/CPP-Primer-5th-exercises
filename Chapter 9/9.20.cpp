#include <iostream>
#include <list>
#include <deque>
using namespace std;
int main()
{
	list<int> li{ 1,2,3,4,5,6,7,8,9,0,234,5,76,547,4676,345,345,6745,764,765,785,897,87,867,867,876,969,679,67 };
	deque<int> di1, di2;
	for (auto i : li)
	{
		if (i % 2 == 0)
			di1.push_back(i);
		else
			di2.push_back(i);
	}
	for (auto i : di1)
		cout << i << " ";
	cout << endl;
	for (auto i : di2)
		cout << i << " ";
	cout << endl;
	return 0;
}