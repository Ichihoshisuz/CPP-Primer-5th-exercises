#include <iostream>
#include <string>
using namespace std;
int main(int argc, char **argv)
{
	cout << argc<<endl;
	string str;
	for (int i = 1; i != argc;++i)
		str += argv[i];
	cout << str << endl;
	system("pause");
	return 0;
}