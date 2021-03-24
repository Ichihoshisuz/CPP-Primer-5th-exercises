#include <iostream>
using namespace std;
int main()
{
	int i;
	cin >> i;
	auto f=[&i]()mutable->bool{
		while (i != 0)
			--i;
		return i == 0;
	};
	if (f())
		cout << "ÒÑµÝ¼õÎª0" << endl;
	else
		cout << "µÝ¼õÊ§°Ü" << endl;
	return 0;
}