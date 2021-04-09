#pragma once

#include <set>
#include <memory>
#include "Bulk_Quote.h"
#include <thread>

class Basket
{
public:
	Basket() :items(compare) {};

	double total_receipt(std::ostream&) const;
	void add_item(const std::shared_ptr<Quote>& sale) { items.insert(sale); }
	void add_item(const Quote& sale) { items.insert(sale.clone()); }
	void add_item(const Quote&& sale) { items.insert(std::shared_ptr<Quote>(std::move(sale.clone()))); }

private:
	static bool compare(const std::shared_ptr<Quote>&, const std::shared_ptr<Quote>&);

	std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items;
};

bool Basket::compare(const std::shared_ptr<Quote>& lhs, const std::shared_ptr<Quote>& rhs)
{
	return  lhs->isbn() < rhs->isbn();
}

double Basket::total_receipt(std::ostream& os) const
{
	double sum = 0.0;
	for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter))
		sum += print_total(os, **iter, items.count(*iter));
	os << "Total Sale: " << sum << std::endl;
	return sum;
}

