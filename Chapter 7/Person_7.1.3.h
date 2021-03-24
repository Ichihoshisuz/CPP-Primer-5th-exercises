#include <iostream>
#include <string>
struct Person
{
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
	os << person.pname()<< " " << person.paddress();
}
