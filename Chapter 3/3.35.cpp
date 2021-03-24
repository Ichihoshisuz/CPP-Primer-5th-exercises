#include <iostream>
using namespace std;
int main()
{
	int a[] = { 1,2,3,4,5,6,7,8,9,0 };
	int *b = begin(a);
	for (b; b < end(a); ++b)
		*b = 0;

	for (auto c : a)
		cout << c << endl;
	system("pause");
	return 0;


}