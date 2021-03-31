#pragma once

#include <iostream>
#include <string>
#include <vector>

// 14.35 14.36
class ReadPringString
{
public:
	ReadPringString(std::ostream& o = std::cout, std::istream& i = std::cin, char c = ' '): 
		os(o), is(i), sep(c) {}
	void operator()(const std::string&) const;
	std::istream& operator()(std::istream&);
private:
	std::istream& is;
	std::ostream& os;
	std::vector<std::string> vs;
	char sep;
};

void ReadPringString::operator()(const std::string& s) const
{
	std::cout << s << std::endl;
}

std::istream& ReadPringString::operator()(std::istream& in)
{
	std::string str;
	std::getline(in, str);
	if (in)
	{
		std::cout << str << std::endl;
		vs.push_back(str);
	}
	else
		std::cout << "Пе line" << std::endl;
	return in;
}