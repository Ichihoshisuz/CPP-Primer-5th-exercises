#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
int main()
{
	vector<double> vi{ 1,2,3,4,5,6,7,8,9,10,11.1 };
	cout << accumulate(vi.cbegin(), vi.cend(), 0)<< endl;
	return 0;
}