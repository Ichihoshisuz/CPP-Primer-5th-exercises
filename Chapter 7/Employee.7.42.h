class Employee
{
	friend::std::istream &read(std::istream &is, Employee person);
public:
	Employee(std::string na = " ", std::string nu = " ", std::string gen = " ", std::string te = " ", int i = 0) :
		name(na), num(nu), gender(gen), team(te), age(i) {}
	Employee(const std::string &s): Employee(s," "," "," ",0){}
	Employee(std::istream &is):Employee() { read(is, *this); }
private:
	std::string name;
	std::string num;
	std::string gender;
	std::string team;
	int age;

};
std::istream &read(std::istream &is, Employee person)
{
	is >> person.name >> person.num >> person.gender >> person.team >> person.age;
	return is;
}