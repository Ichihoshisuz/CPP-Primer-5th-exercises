#pragma once


#include "Disc_Quote.h"

class Bulk_Quote :public Disc_Quote
{
public:
	Bulk_Quote() = default;
	Bulk_Quote(const std::string& str, double price, std::size_t qty, double disc) :
		Disc_Quote(str, price, qty, disc) {
		// 15.26
		// std::cout << "Bulk_Quote 的构造函数" << std::endl;
	};

	//15.27
	// using Disc_Quote::Disc_Quote;

	~Bulk_Quote(){ 
		// 15.26
		// std::cout << "Bulk_Quote 的析构函数" << std::endl; 
	}



	double net_price(std::size_t n) const override;
	void debug() override;
	// 不同于书上的写法
	std::shared_ptr<Quote> clone() const& { return std::make_shared<Bulk_Quote>(*this); }
	Bulk_Quote* clone()&& { return new Bulk_Quote(std::move(*this)); }
};

double Bulk_Quote::net_price(std::size_t n) const
{
	if (n >= quantity)
		return n * price * (1 - discount);
	else
		return n * price;
}

void Bulk_Quote::debug()
{
	Quote::debug();
	std::cout << "size_t quantity: " << quantity << std::endl;
	std::cout << "double discount: " << discount << std::endl;
}


/*
double print_total(std::ostream& os, const Disc_Quote& item, std::size_t n)
{
	double sum = item.net_price(n);
	os << item.isbn() << " " << sum << std::endl;
	return sum;
}
*/

// 15.5
/*
#include "Quote.h"

class Bulk_Quote :public Quote
{
public:
	Bulk_Quote() = default;
	Bulk_Quote(const std::string& str, double p, std::size_t qty, double disc)
		:Quote(str, p), min_qty(qty), discount(disc) {}

	double net_price(std::size_t) const override;
	void debug() override;

private:
	std::size_t min_qty = 0;
	double discount = 0.0;
};

double Bulk_Quote::net_price(std::size_t cnt) const
{
	if (cnt >= min_qty)
		return cnt * (1 - discount) * price;
	else
		return cnt * price;
}

void Bulk_Quote::debug()
{
	Quote::debug();
	std::cout << "size_t min_qty: " << min_qty << std::endl;
	std::cout << "double discount: " << discount << std::endl;
}

*/