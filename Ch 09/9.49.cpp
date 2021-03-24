#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const string &nad(ifstream &is, string &max_word)
{
	string word;
	string list("bdfhkltgjqyp");
	if (is.is_open())
	{
		while (is >> word)
		{
			if ((word.find_first_of(list) == string::npos)&&(max_word.size() < word.size()))
				max_word = word;
		}
	}
	is.close();
	is.clear();
	return max_word;
}
int main()
{
	ifstream words;
	string max_word;
	words.open("dictionary.txt");
	max_word = nad(words,max_word);
	cout << max_word << endl;
}