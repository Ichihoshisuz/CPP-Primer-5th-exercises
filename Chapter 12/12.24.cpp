#include <iostream>
#include <string>
#include <new>
#include <cstring>
using namespace std;
void capacity(char*& c, size_t i,size_t j)
{
	if (i > j)
	{
		delete[] c;
	}
}
int main()
{
	size_t i = 10;
	char* c = new char[i];
	string words;
	while (cin >> words)
	{
		if (words.size() >= i)
		{
			i = words.size()+1;
			delete[] c;
			c = new char[i];
			strcpy_s(c, i, words.c_str());
			cout << c << endl;
		}
		else
		{
			strcpy_s(c, i, words.c_str());
			cout << c << endl;
		}
		
	}
	delete[] c;
	return 0;
}