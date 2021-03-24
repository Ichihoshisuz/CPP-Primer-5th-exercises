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
Sales_data& Sales_data::combine(const Sales_data&trans) 
{
	double dprice = price * (1 - trans.discount/100);
	units_sold += trans.units_sold;
	total += dprice * trans.units_sold;
	return *this;
}
