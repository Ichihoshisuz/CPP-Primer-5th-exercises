#include <iostream>
#include <string>
struct Person
{
	Person() = default;
	Person(const std::string &na, const std::string &ad) :name(na), address(ad) {};
	Person(std::istream &is);
	std::string name;
	std::string address;
	std::string pname() const
	{
		return name;
	}
	std::string paddress() const
	{
		return address;
	}
};
std::istream &read(std::istream &is, Person &person)
{
	is >> person.name >> person.address;
}
std::ostream &os(std::ostream &os, const Person&person)
{
	os << person.pname() << " " << person.paddress();
}
Person::Person(std::istream &is)
{
	read(is, *this);
}