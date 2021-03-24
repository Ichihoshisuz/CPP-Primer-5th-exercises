#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool maxsize(const string &s)
{
	return s.size() >= 5;
}
bool sizesort(vector<string> &s)
{
	auto p=partition(s.begin(), s.end(), maxsize);
	if (p == s.begin())
		return false;
	else
		return true;
}
int main()
{
	vector<string> words;
	string word;
	while (cin >> word)
		words.push_back(word);
	if (sizesort(words))
	{
		for (auto c : words)
			cout << c << ends;
		cout << endl;
	}
	else
		cout << "��û��������ϳ��ȵĵ���" << endl;
	return 0;
}