#include <iostream>
#include <memory>
using namespace std;
struct destination{};
struct connection{};
connection connect(destination* c)
{
	cout << "打开链接" << endl;
	return connection();
}
void disconnect(connection c)
{
	cout << "关闭链接" << endl;
}
void end_connection(connection* c)
{
	disconnect(*c);
}
void f(destination& d)
{
	cout << "调用shared_ptr进行管理" << endl;
	connection c = connect(&d);
	shared_ptr<connection> pc(&c, end_connection);
}
int main()
{
	destination d;
	f(d);
	return 0;
}