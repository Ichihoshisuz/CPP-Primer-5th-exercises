#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
int main()
{
	vector<int> vi{ 1,2,3,4,5,6,7,8,9,0 };
	ostream_iterator<int> out(cout, " ");
	list<int> li;
	copy(vi.rbegin() + 2, vi.rbegin() + 7, back_inserter(li));
	copy(li.begin(), li.end(), out);
	return 0;
}