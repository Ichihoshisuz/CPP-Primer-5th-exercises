#include <iostream>
using namespace std;
int main()
{
	int cnt=0;
	char word;
	while (cin >> word)
	{
		if (word == 'a' || word == 'e' || word == 'i' || word == 'o' || word == 'u')
			++cnt;
	}
	cout << cnt << endl;
	system("pause");
	return 0;
}