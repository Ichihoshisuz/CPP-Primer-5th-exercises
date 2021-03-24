#include <iostream>
#include <string>
using namespace std;
void rep(string &s, const string &oldVal, const string &newVal)
{
	auto i = oldVal.size();
	for (int j = 0; j <= s.size() - i;)
	{
		if (s[j] == oldVal[0])
		{
			int n = 0;
			for (n = 1; n != i; ++n)
			{
				if (s[j + n] != oldVal[n])
					break;
			}
			if (n == i)
			{
				s.replace(j, n, newVal);
				j += newVal.size();
			}
			else
				++j;
		}
	}
}
int main()
{
	string s, s1, s2;
	cin >> s >> s1 >> s2;
	rep(s, s1, s2);
	cout << s << endl;
	return 0;
}