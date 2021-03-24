#include <iostream>
#include <iterator>
#include <fstream>
using namespace std;
int main()
{
	ifstream in("list.txt");
	istream_iterator<int> is(in);
	istream_iterator<int> end;
	ofstream print1("odd.txt");
	ostream_iterator<int> out1(print1," ");
	ofstream print2("even.txt");
	ostream_iterator<int> out2(print2,"\n");
	while (is != end) {
		if (*is & 1)
			*out1++ = *is++;
		else
			*out2++ = *is++;
	}
	return 0;
}