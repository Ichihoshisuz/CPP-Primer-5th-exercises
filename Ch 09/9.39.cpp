#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> vi;
	cout << vi.size() << " " << vi.capacity() << endl;
	int n = 0;
	for (int i = 0; i != 320; ++i)
		vi.push_back(n);
	cout << vi.size() << " " << vi.capacity() << endl;
	return 0;
}