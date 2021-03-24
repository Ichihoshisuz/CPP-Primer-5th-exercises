
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int i, sum = 0;
	vector<int> vSum;
	while (cin >> i)
		vSum.push_back(i);
	if (vSum.size() != 0)
	{
		if (vSum.size() % 2 == 0)
		{
			for (decltype(vSum.size()) a = 0; a < vSum.size(); a = a + 2)
			{
				sum = vSum[a] + vSum[a + 1];
				cout << sum << endl;
			}
		}
		else
		{
			for (decltype(vSum.size()) a = 0; a < (vSum.size() - 1); a = a + 2)
			{
				sum = vSum[a] + vSum[a + 1];
				cout << sum << endl;
			}
			sum = vSum[vSum.size() - 1];
			cout << sum << endl;
		}
	}
	else
		cout << "Error!" << endl;
	system("pause");
	if (vSum.size() != 0)
	{
		if (vSum.size() % 2 == 0)
			for (decltype(vSum.size())a = 0; a < (vSum.size() / 2); a++)
			{
				decltype(vSum.size())b = vSum.size() - 1;
				sum = vSum[a] + vSum[b - a];
				cout << sum << endl;
			}
		else
		{
			for (decltype(vSum.size())a = 0; a < ((vSum.size() - 1) / 2); a++)
			{
				decltype(vSum.size())b = vSum.size() - 1;
				sum = vSum[a] + vSum[b - a];
				cout << sum << endl;
			}
			sum = vSum[(vSum.size() + 1) / 2 - 1];
			cout << sum << endl;
		}
	}
	else
		cout << "Error!" << endl;
	system("pause");
	return 0;
}
