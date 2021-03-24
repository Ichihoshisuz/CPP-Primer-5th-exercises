class Employee
{
	friend::std::istream &read(std::istream &is, Employee person);
public:
	Employee(std::string s=" ",int i=0):
		name(s),num(s),gender(s),team(s),age(i){}
	Employee(std::istream &is) { read(is, *this); }
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