#include <iostream>
#include <string>
#include "Sales_data_ver7.2.1.h"
using namespace std;
int main()
{
	Sales_data sum(cin);
		if (cin)
		{
			double dprice = sum.price*(1 - sum.discount / 100);
			sum.total = sum.units_sold*dprice;
			Sales_data trans;
			while (read(cin, trans))
			{
				if (sum.isbn() == trans.isbn())
					sum = add(sum, trans);
				else
				{
					print(cout, sum);
					cout << endl;
					dprice = trans.price*(1 - trans.discount / 100);
					sum = trans;
					sum.total = sum.units_sold*dprice;
				}
			}
			print(cout, sum);
			cout << endl;
		}
		else
		{
			cout << "请输入正确的数据" << endl;
		}
		system("pause");
		return 0;
}