#include <vector>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	vector<char> vc{ 'm','i','n','a','t','o','a','q','u','a' };
	char *p = &vc[0];
	string s(p, 10);
	cout << s << endl;
	return 0;
}