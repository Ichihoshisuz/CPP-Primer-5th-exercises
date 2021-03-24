#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;
int main()
{
	ifstream in("dictionary.txt");
	istream_iterator<string> read(in);
	istream_iterator<string> end;
	vector<string> words(read, end);
	for (auto c : words)
		cout << c << " ";
	cout << endl;
	return 0;
}