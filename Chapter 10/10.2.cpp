#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;
int main()
{
	list<string> slst{ "a","ab","abc","qw","xxx","cd","ab","qw","a" };
	auto i = count(slst.cbegin(), slst.cend(), "ab");
	cout << "ab�ĳ��ִ���" <<i<<endl;
	return 0;
}