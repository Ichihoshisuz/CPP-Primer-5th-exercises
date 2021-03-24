#include <iostream>
#include "Sales_data.h"
#include <string>
using namespace std;
int main()
{
	Sales_data sum;
	double total;
	if (cin >> sum.isbn >> sum.units_sold>>sum.price)
	{
		total = sum.units_sold*sum.price;
		Sales_data trans;
		while (cin >> trans.isbn >> trans.units_sold>>trans.price)
		{
			if (sum.isbn == trans.isbn)
			{
				sum.units_sold += trans.units_sold;
				total = sum.units_sold*sum.price;
			}
			else
			{
				cout << sum.isbn << " " << total << " " << total / sum.units_sold << endl;
				sum.isbn = trans.isbn;
				sum.price = trans.price;
				sum.units_sold = sum.units_sold;
			}
		}
		cout << sum.isbn << " " << total << " " << total / sum.units_sold << endl;
	}
	else
	{
		cout << "请输入正确的数据" << endl;
	}
	system("pause");
	return 0;
}