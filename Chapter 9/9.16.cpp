#include <iostream>
#include <list>
#include <vector>
using namespace std;
int main()
{
	list<int> li = { 1,2,3,4,5,6,7 };
	vector<int> vi = { 1,2,3,4,5,6,7};
	auto lib = li.cbegin();
	auto lie = li.cend();
	auto vib = vi.cbegin();
	auto vie = vi.cend();
	if (li.size() == vi.size())
	{
		while (lib != lie && vib != vie)
		{
			if (*lib > *vib)
			{
				cout << "����" << endl;
				break;
			}
			else if (*lib < *vib)
			{
				cout << "����" << endl;
				break;
			}
			else
			{
				++lib;
				++vib;
			}
		}
		if (lib == lie && vib == vie)
			cout << "���" << endl;
	}
	else
		cout << "����" << endl;
	return 0;
}