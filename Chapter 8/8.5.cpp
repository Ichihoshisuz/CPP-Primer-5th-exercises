#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	vector<string> vstr, put;
	ofstream fstrm("s.txt", ostream::out);
	if (fstrm)
	{
		string str;
		while (getline(cin, str) && !cin.eof())
			fstrm << str << endl;
	}
	fstrm.close();
	fstrm.clear();
	ifstream in;
	in.open("s.txt", ifstream::in);
	if (in.is_open())
	{
		string str;
		while (in>>str)
			vstr.push_back(str);
	}
	in.close();
	for (auto p : vstr)
		cout << p << endl;
	system("pause");
	return 0;
}