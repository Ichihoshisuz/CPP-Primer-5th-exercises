#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	vector<string> scores = { "S","A","B","C","D","E" };
	int score;
	string lettergrade;
	cin >> score;
	lettergrade = (score < 60) ? scores[5] : scores[5 - (score - 50) / 10];
	cout << lettergrade << endl;
	system("pause");
	return 0;
}