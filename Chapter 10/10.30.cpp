#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	istream_iterator<int> in(cin);
	istream_iterator<int> end;
	vector<int> vi(in,end);
	vector<int> vi1;
	sort(vi.begin(), vi.end());
	ostream_iterator<int> out(cout, " ");
	unique_copy(vi.begin(), vi.end(),out);
	return 0;
}