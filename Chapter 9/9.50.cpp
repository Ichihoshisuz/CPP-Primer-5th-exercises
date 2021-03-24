#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	vector<string> vsi;
	string i;
	double sum = 0;
	while (cin >> i)
		vsi.push_back(i);
	for (auto c : vsi)
		sum += stod(c);
	cout << sum << endl;
	return 0;

}