#include <iostream>
#include <string>
#include <vector>
#include "9.51.h"
using namespace std;
int main()
{
	string data("Feb 2, 990");
	string data1("Mar 17 1789");
	string data2("12/12/1");
	calendar s(data);
	out(cout, s);
	calendar s1(data1);
	out(cout, s1);
	calendar s2(data2);
	out(cout, s2);
	return 0;
}