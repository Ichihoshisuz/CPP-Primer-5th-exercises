#include<iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main()
{
	vector<string> words;
	string word;
	ifstream is("dictionary.txt");
	while (is >> word)
		words.push_back(word);
	int x = count_if(words.cbegin(), words.cend(), [](const string &s) {
		return s.size() > 6;
	});
	cout << "�����г��ȳ���6�Ĳ���Ϊ" << x << endl;
	return 0;
}