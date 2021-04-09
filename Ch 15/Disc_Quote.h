#pragma once

#include <iostream>
#include <string>
#include "Quote.h"

class Disc_Quote :public Quote
{
public:
	Disc_Quote() = default;
	Disc_Quote(const std::string& str, double price, std::size_t qty, double disc) :
		Quote(str, price), quantity(qty), discount(disc) {};

	double net_price(std::size_t) const = 0;

protected:
	std::size_t quantity = 0;
	double discount = 0.0;
};

