#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> vi1;
	vector<int> vi2;
	int i;
	while (cin >> i)
		vi1.push_back(i);
	cin.clear();
	while (cin >> i)
		vi2.push_back(i);
	if (vi1 == vi2)
		cout << "���" << endl;
	else if (vi1 < vi2)
		cout << "С��" << endl;
	else
		cout << "����" << endl;
	return 0;
}