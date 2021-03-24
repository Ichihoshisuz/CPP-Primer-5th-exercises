struct Person
{
	friend std::istream &read(std::istream &is, Person &person);
public:
	Person() = default;
	Person(const std::string &na, const std::string &ad) :name(na), address(ad) {};
	explicit Person(std::istream &is);
	std::string pname() const
	{
		return name;
	}
	std::string paddress() const
	{
		return address;
	}
private:
	std::string name;
	std::string address;
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