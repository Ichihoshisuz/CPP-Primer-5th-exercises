#include <iostream>
#include <forward_list>
using namespace std;
int main()
{
	forward_list<int> fli{ 1,2,3,42,42,42,52,5,536,36,37,4,76,875,86,986,98,967,45,64 };
	auto prev = fli.before_begin();
	auto curr = fli.begin();
	while(curr!=fli.cend())
	{
	if (*curr & 1)
		curr = fli.erase_after(prev);
	else
	{
		prev=curr;
		++curr;
	}
	}
	for (auto c : fli)
		cout << c << " ";
	cout << endl;
	return 0;
}