#include <iostream>
#include "Sales_data.h"
#include <string>
using namespace std;
int main()
{
	Sales_data sum;
	if (cin >> sum.SN>> sum.units_sold >> sum.price>>sum.discount)
	{
		double dprice = sum.price*(1 - sum.discount / 100);
		sum.total = sum.units_sold*dprice;
		Sales_data trans;
		while (cin >> trans.SN>> trans.units_sold >> trans.price>>trans.discount)
		{
			if (sum.isbn() == trans.isbn())
			{
				sum.combine(trans);
			}
			else
			{
				cout << sum.SN << " " << sum.total << " " << sum.total / sum.units_sold << endl;
				dprice = trans.price*(1 - trans.discount / 100);
				sum = trans;
				sum.total = sum.units_sold*dprice;
			}
		}
		cout << sum.SN<< " " << sum.total << " " << sum.total / sum.units_sold << endl;
	}
	else
	{
		cout << "请输入正确的数据" << endl;
	}
	system("pause");
	return 0;
}