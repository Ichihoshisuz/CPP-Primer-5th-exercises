#include <iostream>
#include <string>
using namespace std;
int main()
{
	int score;
	string str;
	cin >> score;
	str = (score >= 90 ? "high pass" : (score > 75) ? "pass" : (score >= 60) ? "low pass" : "fail");
	cout << str << endl;
	if (score >= 90)
		str = "high pass";
	else if (score > 75)
		str = "pass";
	else if (score >= 60)
		str = "low pass";
	else
		str = "fail";
	cout << str << endl;
	system("pause");
	return 0;
}