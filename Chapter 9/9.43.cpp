#include <iostream>
#include <string>
using namespace std;
void rep(string &s, const string &oldVal, const string &newVal)
{
	auto nbeg = newVal.cbegin();
	auto nend = newVal.cend();
	for (auto sbeg = s.begin(); sbeg <= s.end()-oldVal.size();)
	{
		auto obeg = oldVal.cbegin();
		auto oend = oldVal.cend();
		if (*sbeg == *obeg)
		{
			++obeg;
			for (auto ps = sbeg + 1; obeg != oend; ++obeg,++ps)
			{
				if (*ps != *obeg)
					break;
			}
		}
		if (obeg == oend)
		{
			sbeg = s.erase(sbeg, sbeg + oldVal.size());
			sbeg = s.insert(sbeg, nbeg, nend) + newVal.size();
		}
		else
			++sbeg;
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