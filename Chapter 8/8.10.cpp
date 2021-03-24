#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	ifstream in;
	in.open("s.txt");
	if (in.is_open())
	{
		vector<string> vstr;
		string line;
		while (getline(in, line))
			vstr.push_back(line);
		in.close();
		istringstream istr;
		for (auto c : vstr)
		{
			string s;
			istr.str(c);
			while(istr >> s)
				cout << s << endl;
		}
	}
	else
		cout << "³ö´í" << endl;
	system("pause");
	return 0;
}