#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;
int main()
{
	list<int> li{ 1,2,3,0,4,5,0,6,7,0,43,0,23,123,54,7 };
	auto peg = find(li.rbegin(), li.rend(), 0);
	for (auto beg = (++peg).base(); beg != li.end(); ++beg)
		cout << *beg << " ";
	cout << endl;
	return 0;
}