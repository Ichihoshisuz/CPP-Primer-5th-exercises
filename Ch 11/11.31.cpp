#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	multimap<string, string> author_works;
	ifstream in("author_works.txt");
	string line;
	while (getline(in,line))
	{
		auto space = find(line.begin(), line.end(), ' ');
		string author(line.begin(), space);
		string works(++space, line.end());
		string work;
		istringstream strm(works);
		while (strm >> work)
			author_works.insert({ author,work });
	}

	string del;
	cin >> del;
	auto iter = author_works.find(del);
	if (iter != author_works.cend())
	{
		auto count = author_works.erase(del);
		cout << "删除了的数量为：" << count << endl;
	}
	else
		cout << "没有该作者" << endl;
	for (auto& c : author_works)
	{
		cout << c.first << " " << c.second << endl;
	}
	return 0;

}