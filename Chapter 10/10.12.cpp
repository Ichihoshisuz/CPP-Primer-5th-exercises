#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Sales_data.h"
using namespace std;
bool isbn(const Sales_data &s1,const Sales_data &s2)
{
	return s1.isbn() < s2.isbn();
}
void compareIsbn(vector<Sales_data> vSales_data)
{
	sort(vSales_data.begin(), vSales_data.end(), isbn);
	for (auto c : vSales_data)
		cout << c.isbn() << ' ' << endl;
	return;
}
int main()
{
	vector<Sales_data> vsd;
	Sales_data trans;
	while (read(cin, trans))
		vsd.push_back(trans);
	compareIsbn(vsd);
	return 0;

}