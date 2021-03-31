#pragma once

class IfElseThen
{
public:
	IfElseThen() = default;
	IfElseThen(int i1, int i2, int i3) :val1(i1), val2(i2), val3(i3) {}
	int operator()(int i1, int i2, int i3) { return i1 ? i2 : i3; }
private:
	int val1;
	int val2;
	int val3;
};