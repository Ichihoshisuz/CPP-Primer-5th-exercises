/*
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> vSum;
	int i,sum;
	while (cin >> i)
		vSum.push_back(i);
	auto beg = vSum.begin(), end = vSum.end();
	decltype(beg)v1, v2;
	if (beg != end)
	{
		for (auto v=beg ; v < (end-1); v += 2)
		{
			v1 = v + 1;
			sum = (*v) + (*v1);
			cout << sum << " ";
		}
		if (vSum.size() % 2 != 0)
		{
			int j = *(end - 1);
			cout << j << endl;
		}
		else
			cout << endl;
		for (auto v = beg; v < (beg+(end - beg)/2); v += 1)
		{
			v2 = beg + (end - v - 1);
			sum = *v + (*v2);
			cout << sum << " ";
		}
		if ((beg - end) % 2 != 0)
		{
			int j = *(beg + (end - beg) / 2);
			cout << j << endl;
		}
	}
	system("pause");
	return 0;
}
*/