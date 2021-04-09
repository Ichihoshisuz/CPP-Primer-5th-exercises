#pragma once

#include "Disc_Quote.h"

class Limited_Quote :public Disc_Quote
{
public:
	Limited_Quote() = default;
	Limited_Quote(const std::string& str, double sales_price, std::size_t n, double disc) :
		Disc_Quote(str, sales_price, n, disc) {}

	double net_price(std::size_t n) const override;
	void debug() override;
};

double Limited_Quote::net_price(std::size_t n) const
{
	if (n <= quantity)
		return n * price * (1 - discount);
	else
		return quantity * price * (1 - discount) + (n - quantity) * price;
}

void Limited_Quote::debug()
{
	Quote::debug();
	std::cout << "size_t quantity: " << quantity << std::endl;
	std::cout << "double discount: " << discount << std::endl;
}

//15.7
/*

#include "Quote.h"

class Limited_Quote :public Quote
{
public:
	Limited_Quote() = default;
	Limited_Quote(const std::string& str, double p, std::size_t qty, double disc)
		:Quote(str, p), min_qty(qty), discount(disc) {}

	double net_price(std::size_t) const override;
	void debug() override;

private:
	std::size_t min_qty = 0;
	double discount = 0.0;
};

double Limited_Quote::net_price(std::size_t cnt) const
{
	if (cnt <= min_qty)
		return cnt * (1 - discount) * price;
	else
		return cnt * price;
}

void Limited_Quote::debug()
{
	Quote::debug();
	std::cout << "size_t min_qty: " << min_qty << std::endl;
	std::cout << "double discount: " << discount << std::endl;
}
*/