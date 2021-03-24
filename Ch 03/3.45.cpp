#include <iostream>
#include <ctime>
using namespace std;
int main()
{
	srand((unsigned)time(NULL));
	int ia[3][4];
	for (auto &c : ia)
	{
		for (auto &d : c)
			d = rand() % 100;
	}
	for (auto &c : ia)
	{
		for (auto &d : c)
			cout << d << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}