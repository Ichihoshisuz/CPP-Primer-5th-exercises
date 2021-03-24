#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	vector<int> vi;
	int i = 0;
	while (cin >> i) {
		vi.push_back(i);
	}
	int j = count(vi.cbegin(), vi.cend(), 10);
	cout << "出现次数" << j << endl;
	return 0;
}