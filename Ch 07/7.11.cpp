#include <iostream>
#include <string>
#include "Sales_data_ver7.1.4.h"
using namespace std;
int main()
{
	Sales_data data1;
	Sales_data data2("2017");
	Sales_data data3("2017", 20, 5, 120);
	Sales_data data4(cin); 
	print(cout, data1);
	cout << endl;
	print(cout, data2);
	cout << endl;
	print(cout, data3);
	cout << endl;
	print(cout, data4);
	cout << endl;
	system("pause");
	return 0;
}