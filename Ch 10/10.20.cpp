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
	cout << "单词中长度超过6的部分为" << x << endl;
	return 0;
}