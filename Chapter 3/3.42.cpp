/*#include <iostream>
#include <vector>
#include <cstddef>
using namespace std;
int main()
{
	int i,arr[10];
	int *beg = begin(arr);
	vector<int> ivec;
	while (cin >> i&&(ivec.size()!=10))
		ivec.push_back(i);
	for (auto c : ivec)
	{
		*beg = c;
		++beg;
	}
	for (auto c : arr)
		cout << c << " ";
	cout << endl;
	system("pause");
	return 0;
}*/