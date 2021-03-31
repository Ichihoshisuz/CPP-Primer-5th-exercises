#pragma once

#include <vector>
#include <algorithm>
using namespace std;

class IntCompare
{
public:
	IntCompare(int v) :val(v) {}
	bool operator()(int v) const { return val == v; }
private:
	int val;
};

void InCompare_replace_if(vector<int>& vi, const IntCompare& ic, int new_val)
{
	replace_if(vi.begin(), vi.end(), ic, new_val);
}