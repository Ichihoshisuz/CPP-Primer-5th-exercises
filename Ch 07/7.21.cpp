#include <iostream>
#include <string>
#include "Sales_data_ver7.2.1.h"
using namespace std;
int main()
{
	Sales_data sum(cin);
	if (cin)
	{
		Sales_data trans;
		while (read(cin, trans))
		{
			if (sum.isbn() == trans.isbn())
				sum = add(sum, trans);
			else
			{
				print(cout, sum);
				cout << endl;
				sum = trans;
			}
		}
		print(cout, sum);
		cout << endl;
	}
	else
	{
		cout << "��������ȷ������" << endl;
	}
	system("pause");
	return 0;
}