#pragma once

#include <iostream>
#include <string>

class Sales_data
{
	friend std::istream& read(std::istream& ip, Sales_data& item);
	friend std::ostream& print(std::ostream& op, const Sales_data& item);
	friend Sales_data add(const Sales_data& total, const Sales_data& trans);
	//重载输入、输出运算符
	//14.2 14.6 14.9 
	friend std::ostream& operator<<(std::ostream&, const Sales_data&);
	friend std::istream& operator>>(std::istream&, Sales_data&);
	// 14.2 14.13 
	friend Sales_data operator+(const Sales_data&, const Sales_data&);
	friend Sales_data operator-(const Sales_data&, const Sales_data&);
	// 14.3.1
	friend bool operator==(const Sales_data&, const Sales_data&);
	friend bool operator!=(const Sales_data&, const Sales_data&);
	// 14.3.2 Sales_data 的性质决定了并不一定需要关系运算符

public:
	Sales_data(const std::string& s, int n, double dc, double p) :
		SN(s), units_sold(n), discount(dc), price(p), total(units_sold* price* (1 - discount / 100)) {}
	Sales_data(std::string s = "") :Sales_data(s, 0, 0, 0) {}
	Sales_data(const std::string& s, int n) :Sales_data(s, n, 0, 0) {}
	Sales_data(std::istream& is) :Sales_data() { read(is, *this); }

	// 14.2 14.20
	Sales_data& operator+=(const Sales_data&);
	Sales_data& operator-=(const Sales_data&);
	// 14.22
	Sales_data& operator=(const std::string&);
	// 14.45 14.46
	// explicit operator const std::string& () { return SN; }
	// explicit operator double() { return total; }

	std::string isbn() const { return SN; }
	Sales_data& combine(const Sales_data& trans);
	double aver_price()const;

private:
	int units_sold = 0;
	double discount = 0;
	double price = 0;
	double total = 0;
	std::string SN;
};

Sales_data& Sales_data::combine(const Sales_data& trans)
{
	double dprice = price * (1 - trans.discount / 100);
	units_sold += trans.units_sold;
	total += dprice * trans.units_sold;
	return *this;
}

inline double Sales_data::aver_price()const
{
	if (units_sold != 0)
		return total / units_sold;
	else
		return 0;
}

std::istream& read(std::istream& ip, Sales_data& item)
{
	ip >> item.SN >> item.units_sold >> item.price >> item.discount;
	item.total = item.units_sold * item.price * (1 - item.discount / 100);
	return ip;
}

std::ostream& print(std::ostream& os, const Sales_data& item)
{
	os << item.isbn() << " " << item.units_sold << " " << item.discount << "% " << item.total;
	return os;
}

Sales_data add(const Sales_data& total, const Sales_data& trans)
{
	Sales_data sum = total;
	sum.combine(trans);
	return sum;
}

std::ostream& operator<<(std::ostream& os, const Sales_data& item)
{
	os << item.isbn() << " " << item.units_sold << " "
		<< item.price << " " << item.discount << "% " << item.total;
	return os;
}

// 需要处理输入失败的情况
std::istream& operator>>(std::istream& is, Sales_data& item)
{
	is >> item.SN >> item.units_sold >> item.price >> item.discount;
	if (is)
		item.total = item.units_sold * item.price * (1 - item.discount / 100);
	else
		item = Sales_data();
	return is;
}

Sales_data& Sales_data::operator+=(const Sales_data& rhs)
{
	units_sold += rhs.units_sold;
	total += rhs.total;
	return *this;

	// 14.21 要求
	/*
	Sales_data sum = *this + rhs;
	units_sold = sum.units_sold;
	total = sum.total;
	return *this;
	*/
}

Sales_data& Sales_data::operator-=(const Sales_data& rhs)
{
	units_sold -= rhs.units_sold;
	total -= rhs.total;
	return *this;
}

// 14.22
Sales_data& Sales_data::operator=(const std::string& str)
{
	SN = str;
	return *this;
}

// 14.13 从头实现一遍
// 假定 discount 不变
Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs)
{
	Sales_data sum = lhs;
	sum.units_sold += rhs.units_sold;
	sum.total = rhs.total;
	return sum;
}

Sales_data operator-(const Sales_data& lhs, const Sales_data& rhs)
{
	Sales_data sub = lhs;
	sub -= rhs;
	return sub;
}

bool operator==(const Sales_data& lhs, const Sales_data& rhs)
{
	return lhs.SN == rhs.SN
		&& lhs.price == rhs.price
		&& lhs.units_sold == rhs.units_sold
		&& lhs.discount == rhs.discount;
}

bool operator!=(const Sales_data& lhs, const Sales_data& rhs)
{
	return !(lhs == rhs);
}
