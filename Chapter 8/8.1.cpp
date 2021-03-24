#include <iostream>
#include <sstream>
#include <stdexcept>
using namespace std;
istream &out(istream &is)
{
	int s;
	while (is >> s,!is.eof())
	{
		if (is.bad())
			throw runtime_error("������ϵͳ������");
		else if (is.fail())
		{
			cout << "�������" << endl;
			is.clear();
			is.ignore(5, '\n');
			continue;
		}
		cout << s << endl;
	}
	is.clear();
	return is;
}
int main()
{
	ostringstream ostr;
	ostr << "Hello World!" << endl;
	istringstream istr(ostr.str());
	out(istr);
	system("pause");
	return 0;
}