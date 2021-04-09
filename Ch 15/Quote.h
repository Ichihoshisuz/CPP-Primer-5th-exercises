#pragma once

#include <string>
#include <iostream>

class Quote
{
public:
	Quote() = default;
	Quote(const std::string& book, double sales_price) :
		bookNo(book), price(sales_price) { 
		// 15.26
		// std::cout << "Quote 的构造函数" << std::endl;
	}
	virtual ~Quote() { 
		// 15.26
		// std::cout << "Quote 的析构函数" << std::endl; 
	}

	std::string isbn() const { return bookNo; }
	
	virtual double net_price(std::size_t n) const { return n * price; }
	virtual void debug();
	// 不同于书上的写法
	virtual std::shared_ptr<Quote> clone() const& { return std::make_shared<Quote>(*this); }
	virtual Quote* clone()&& { return new Quote(std::move(*this)); }

private:
	std::string bookNo;
protected:
	double price = 0.0;
};

void Quote::debug()
{
	std::cout << "string bookNo: " << bookNo << std::endl;
	std::cout << "double price: " << price << std::endl;
}


double print_total(std::ostream& os, const Quote& item, std::size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << std::endl
		<< "sold: " << n << std::endl
		<< "total due: " << ret << std::endl;
	return ret;
}
