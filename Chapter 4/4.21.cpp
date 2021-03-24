/*
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{
	srand((unsigned)time(NULL));
	vector<int> vint;
	for (int i = 0; i != 20; ++i)
	{
		vint.push_back(rand() % 100);
		cout << vint[i] << " ";
	}
	cout << endl;
	for (auto beg = vint.begin(); beg != vint.cend(); ++beg) 
	{
		((*beg) % 2 != 0) ? (*beg) *= 2 : (*beg);
		cout << *beg << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
*/