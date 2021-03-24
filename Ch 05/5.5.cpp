#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	vector<string> scores = { "S","A","B","C","D","E"};
	int score;
	string lettergrade;
	cin >> score;
	if (score < 60)
	{
		lettergrade = scores[5];
	}
	else
	{
		lettergrade = scores[5 - (score - 50) / 10];
	}
	cout << lettergrade << endl;
	system("pause");
	return 0;
}