#include <iostream>
#include <vector>
#include <list>
using namespace std;
int main()
{
	int ia[] = { 0,1,1,2,3,5,8,13,21,55,89 };
	vector<int> vi;
	list<int> li;
	for (int *p = begin(ia),*q = end(ia); p != q; ++p)
	{
		vi.push_back(*p);
		li.push_back(*p);
	}
	for (auto p = li.cbegin(), q = li.cend(); p != q; )
	{
		if (*p & 1)
			p=li.erase(p);
		else
			++p;

	}
	for (auto p = vi.cbegin(), q = vi.cend(); p != q; )
	{
		if (!(*p & 1))
		{
			p = vi.erase(p);
			q = vi.cend();
		}
		else
			++p;
	}
	for (auto c : li)
		cout << c << " ";
	cout << endl;
	for(auto c:vi)
		cout << c << " ";
	cout << endl;
	return 0;
}