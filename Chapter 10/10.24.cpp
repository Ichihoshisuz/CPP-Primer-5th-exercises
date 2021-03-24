#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>
using namespace std;
using namespace placeholders;
bool more_sz(const string &s, int i)
{
	return s.size() < i;
}
void check_size(vector<int> &vi, const string &s)
{

	auto p = find_if(vi.begin(), vi.end(), bind(more_sz, s, _1));
	if (p == vi.end())
		cout << "û���ҵ�������ֵ" << endl;
	else
		cout << "������ֵΪ��" << *p << endl;
	return;
}
int main()
{
	vector<int> vi{ 1,2,3,4,5,6,7,8,9,10 };
	string s;
	cin >> s;
	check_size(vi, s);
	return 0;
}
