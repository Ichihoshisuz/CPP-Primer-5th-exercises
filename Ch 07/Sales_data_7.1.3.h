struct Sales_data
{
	std::string isbn() const
	{
		return SN;
	}
	Sales_data& combine(const Sales_data&trans);
	int units_sold = 0;
	double discount = 0;
	double price = 0;
	double total = 0;
	std::string SN;
};
Sales_data &Sales_data::combine(const Sales_data &trans)
{
	double dprice = price * (1 - trans.discount / 100);
	units_sold += trans.units_sold;
	total += dprice * trans.units_sold;
	return *this;
}
std::istream &read(std::istream &ip, Sales_data &item)
{
	ip >> item.SN >> item.units_sold >> item.price >> item.discount;
	item.total = item.units_sold*item.price*(1 - item.discount / 100);
	return ip;
}
std::ostream &print(std::ostream &op, const Sales_data &item)
{
	op << item.isbn() << " " << item.units_sold << " " << item.discount << "% " << item.total;
	return op;
}
Sales_data add(const Sales_data &total, const Sales_data &trans)
{
	Sales_data sum = total;
	sum.combine(trans);
	return sum;
}
