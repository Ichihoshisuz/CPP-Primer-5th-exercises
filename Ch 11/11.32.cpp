#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
void display(multimap<string, string>& out)
{
	for (auto& c : out)
	{
		cout << c.first << " " << c.second << endl;
	}
}
int main()
{
	multimap<string, string> author_works;
	ifstream in("author_works.txt");
	string line;
	while (getline(in, line))
	{
		auto space = find(line.begin(), line.end(), ' ');
		string author(line.begin(), space);
		string works(++space, line.end());
		string work;
		vector<string> vs;
		istringstream strm(works);
		while (strm >> work)
			vs.push_back(work);
		sort(vs.begin(), vs.end());
		for (auto& c : vs)
			author_works.insert({ author,c });
	}
	display(author_works);
	return 0;
}