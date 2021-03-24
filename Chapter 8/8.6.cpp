#include <iostream>
#include <fstream>
#include "Sales_data.h"
#include <string>
using namespace std;
int main(int argc,char **argv)
{
	Sales_data sum;
	double total;
	string str = argv[1];
	str += ".txt";
	ifstream in;
	in.open(str);
	if (in.is_open())
	{
		if (in >> sum.isbn >> sum.units_sold >> sum.price)
		{
			total = sum.units_sold*sum.price;
			Sales_data trans;
			while (in >> trans.isbn >> trans.units_sold >> trans.price)
			{
				if (sum.isbn == trans.isbn)
				{
					sum.units_sold += trans.units_sold;
					total = sum.units_sold*sum.price;
				}
				else
				{
					cout << sum.isbn << " " << sum.price << " " << sum.units_sold << endl;
					sum.isbn = trans.isbn;
					sum.price = trans.price;
					sum.units_sold = sum.units_sold;
				}
			}
			cout << sum.isbn << " " << sum.price << " " << sum.units_sold << endl;
		}
		else
		{
			cout << "请输入正确的数据" << endl;
		}
	}
	else
		cout << "打开失败" << endl;
	system("pause");
	return 0;
}