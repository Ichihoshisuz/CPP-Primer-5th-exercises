#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <memory>
#include <map>
#include <set>
#include "TextQuery_ver12.32.h"
using namespace std;
void runQueries(ifstream& in)
{
	TextQuery tq(in);
	string s;
	while (cin >> s && s != "q")
	{
		print(cout, tq.query(s)) << endl;
	}
}
int main()
{
	ifstream in("News.txt");
	runQueries(in);
	return 0;
}