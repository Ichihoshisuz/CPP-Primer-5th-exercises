#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
using namespace placeholders;
bool more_six(const string &s,string::size_type sz)
{
	return s.size() > sz;
}
int main()
{
	vector<string> words;
	string word;
	ifstream is("dictionary.txt");
	while (is >> word)
		words.push_back(word);
	int x = count_if(words.begin(), words.end(), bind(more_six, _1, 6));
	cout << x << endl;
	return 0;
}