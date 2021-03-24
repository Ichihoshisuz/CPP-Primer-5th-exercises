#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> scores(11, 0);
	auto v1 = scores.begin();
	int grade;
	while (cin >> grade)
	{
		v1 += grade / 10;
		*v1 += 1;
		v1 = scores.begin();
	}
	for (auto s : scores)
		cout << s << " ";
	cout << endl;
	system("pause");
	return 0;
}