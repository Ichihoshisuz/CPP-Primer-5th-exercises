#include <iostream>
#include <memory>
using namespace std;
struct destination{};
struct connection{};
connection connect(destination* c)
{
	cout << "������" << endl;
	return connection();
}
void disconnect(connection c)
{
	cout << "�ر�����" << endl;
}
void end_connection(connection* c)
{
	disconnect(*c);
}
void f(destination& d)
{
	cout << "����shared_ptr���й���" << endl;
	connection c = connect(&d);
	shared_ptr<connection> pc(&c, end_connection);
}
int main()
{
	destination d;
	f(d);
	return 0;
}