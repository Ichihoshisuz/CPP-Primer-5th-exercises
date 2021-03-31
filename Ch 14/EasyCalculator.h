#pragma once

#include <map>
#include <functional>
#include <string>

using namespace std;

map<string, function<int(int, int)>> binops = {
	{"+", plus<int>()},
	{"-", minus<int>()},
	{"*", multiplies<int>()},
	{"/", divides<int>()},
	{"%", modulus<int>()}
};