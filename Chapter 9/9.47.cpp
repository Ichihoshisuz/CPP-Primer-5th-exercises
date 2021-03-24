#include <string>
#include <iostream>
using namespace std;
size_t find(const string &s,const string &p)
{
	auto pos=s.find_first_of(p);
	return pos;
}
size_t rfind(const string &s, const string &p)
{
	auto pos = s.find_first_not_of(p);
	return pos;

}
int main()
{
	string s("abcdefg"), p;
	cin >> p;
	auto pos = find(s, p);
	auto rpos = rfind(s, p);
	cout << pos << " " << rpos << endl;
	return 0;
}