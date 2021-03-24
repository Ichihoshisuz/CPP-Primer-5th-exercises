#include <iostream>
#include <string>
#include <forward_list>
using namespace std;
void insert(forward_list<string> &flst, const string &str1, const string &str2)
{
	auto prev = flst.before_begin();
	auto pstr = flst.begin();
	while (pstr != flst.cend())
	{
		if (*pstr == str1)
		{
			flst.insert_after(pstr, str2);
			break;
		}
		else
		{
			prev = pstr;
			++pstr;
		}
	}
	if (pstr == flst.cend())
		flst.insert_after(prev, str2);
}
int main()
{
	forward_list<string> flst{ "he","ll","o","wor","ld" };
	string str1, str2;
	cin >> str1 >> str2;
	insert(flst, str1, str2);
	for (const auto &s : flst)
		cout << s << " ";
	cout << endl;
	return 0;
}