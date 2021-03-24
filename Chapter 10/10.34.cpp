#include <iostream>
#include <iterator>
#include <vector>
using namespace std;
int main()
{
	vector<int> vi{ 1,2,3,4,5,6,7,8,9,10,11 };
	for (auto rbeg = vi.crbegin(); rbeg != vi.crend(); ++rbeg)
		cout << *rbeg << endl;
	return 0;
}