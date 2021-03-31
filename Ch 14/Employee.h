#pragma once
#pragma once

#include <iostream>
#include <string>

class Employee
{
	friend std::istream& read(std::istream& is, Employee& person);
	// 14.8
	friend std::ostream& operator<<(std::ostream& os, const Employee& person);
	// 14.12
	friend std::istream& operator>>(std::istream& is, Employee& person);
	// 14.17
	friend bool operator==(const Employee&, const Employee&);
	friend bool operator!=(const Employee&, const Employee&);
	// 14.19
	friend bool operator<(const Employee&, const Employee&);
	friend bool operator>(const Employee&, const Employee&);
	friend bool operator<=(const Employee&, const Employee&);
	friend bool operator>=(const Employee&, const Employee&);

public:
	Employee(std::string s = " ") :
		name(s), id(s), gender(s), team(s), age(0) {}
	Employee(std::istream& is) :age(0) { read(is, *this); }

	// 14.49
	explicit operator bool() const;

private:
	std::string name;
	std::string id;
	std::string gender;
	std::string team;
	int age;
};

Employee::operator bool() const
{
	return name != "" && id != "" && gender != "" && team != "" && age != 0;
}

std::istream& read(std::istream& is, Employee& person)
{
	is >> person.name >> person.id >> person.age >> person.gender >> person.team;
	if (!is)
		person = Employee();
	return is;
}

std::ostream& operator<<(std::ostream& os, const Employee& person)
{
	os << "name: " << person.name << std::endl
		<< "id: " << person.id << std::endl
		<< "age: " << person.age << std::endl
		<< "gender: " << person.gender << std::endl
		<< "team: " << person.team;
	return os;
}

std::istream& operator>>(std::istream& is, Employee& person)
{
	is >> person.name >> person.id >> person.age >> person.gender >> person.team;
	if (!is)
		person = Employee();
	return is;
}

bool operator==(const Employee& lhs, const Employee& rhs)
{
	return lhs.id == rhs.id;
}

bool operator!=(const Employee& lhs, const Employee& rhs)
{
	return lhs.id != rhs.id;
}

bool operator<(const Employee& lhs, const Employee& rhs)
{
	return lhs.id < rhs.id;
}

bool operator>(const Employee& lhs, const Employee& rhs)
{
	return lhs.id > rhs.id;
}

bool operator<=(const Employee& lhs, const Employee& rhs)
{
	return lhs.id <= rhs.id;
}

bool operator>=(const Employee& lhs, const Employee& rhs)
{
	return lhs.id >= rhs.id;
}