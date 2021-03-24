#include <string>

using namespace std;

class Employee
{
public:
	Employee() = default;
	Employee(const string& n) :name(n), ID(number++) {}

	Employee(const Employee& rhs):name(rhs.name),ID(number++){}
	Employee& operator=(const Employee& rhs)
	{
		name = rhs.name;
	}
private:
	static int number;
	int ID = 0;
	string name;

};