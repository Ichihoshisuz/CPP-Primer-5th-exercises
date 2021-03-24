/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	vector<int> v1;
	if (v1.cbegin()!=v1.cend())
	{
		auto beg = v1.begin(), end = v1.end();
		for (beg; beg != end; ++beg)
			cout << *beg << " ";
		cout << endl;
	}
	vector<int> v2(10);
	if (v2.cbegin() != v2.cend())
	{
		auto beg = v2.begin(), end = v2.end();
		for (beg; beg != end; ++beg)
			cout << *beg << " ";
		cout << endl;
	}
	vector<int> v3(10,42 );
	if (v3.cbegin() != v3.cend())
	{
		auto beg = v3.begin(), end = v3.end();
		for (beg; beg != end; ++beg)
			cout << *beg << " ";
		cout << endl;
	}
	vector<int> v4{ 10 };
	if (v4.cbegin() != v4.cend())
	{
		auto beg = v4.begin(), end = v4.end();
		for (beg; beg != end; ++beg)
			cout << *beg << " ";
		cout << endl;
	}
	vector<int> v5{ 10,42 };
	if (v5.cbegin() != v5.cend())
	{
		auto beg = v5.begin(), end = v5.end();
		for (beg; beg != end; ++beg)
			cout << *beg << " ";
		cout << endl;
	}
	vector<string> v6{ 10 };
	if (v6.cbegin() != v6.cend())
	{
		auto beg = v6.begin(), end = v6.end();
		for (beg; beg != end; ++beg)
			cout << *beg << " ";
		cout << endl;
	}
	vector<string> v7{ 10,"hi" };
	if (v7.cbegin() != v7.cend())
	{
		auto beg = v7.begin(), end = v7.end();
		for (beg; beg != end; ++beg)
			cout << *beg << " ";
		cout << endl;
	}
	system("pause");
	return 0;
}
*/