#include <iostream>
#include <memory>
#include <new>
#include <string>
#include <cstring>
using namespace std;
int main()
{
	const char* a = "Hello";
	const char* b = " World!";
	char* c = new char[strlen(a) + strlen(b) + 1];
	
	strcpy_s(c, strlen(a) + strlen(b) + 1, a);
	strcat_s(c, strlen(a) + strlen(b) + 1, b);

	cout << c << endl;

	string s1{ "ff" };
	string s2{ "14" };
	strcpy_s(c, strlen(a) + strlen(b) + 1, (s1 + s2).c_str());
	cout << c << endl;
	delete[] c;
	return 0;
}