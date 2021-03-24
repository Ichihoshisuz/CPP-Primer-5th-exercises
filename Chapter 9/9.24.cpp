#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> vi;
	auto val1 = vi.at(0);
	auto val2 = vi[0];
	auto val3 = vi.front();
	auto val4 = vi.begin();
	return 0;
}