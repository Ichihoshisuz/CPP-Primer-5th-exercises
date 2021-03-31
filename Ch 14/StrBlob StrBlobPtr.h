#pragma once

#include <string>
#include <vector>
#include <memory>
#include <stdexcept>

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob
{
	friend class StrBlobPtr;
	friend class ConstStrBlobPtr;

	// 14.16
	friend bool operator==(const StrBlob&, const StrBlob&);
	friend bool operator!=(const StrBlob&, const StrBlob&);
	// 14.18
	friend bool operator<(const StrBlob&, const StrBlob&);
	friend bool operator>(const StrBlob&, const StrBlob&);
	friend bool operator<=(const StrBlob&, const StrBlob&);
	friend bool operator>=(const StrBlob&, const StrBlob&);

	using size_type = std::vector<std::string>::size_type;

public:
	StrBlob() :data(std::make_shared<std::vector<std::string>>()) {}
	StrBlob(std::initializer_list<std::string>& il) :
		data(std::make_shared <std::vector<std::string>>(il)) {}
	explicit StrBlob(std::shared_ptr<std::vector<std::string>>& sptr) :data(sptr) {}
	StrBlob(const StrBlob& rhs);
	StrBlob& operator=(const StrBlob& rhs);
	~StrBlob() {}
	
	// 14.26
	std::string& operator[](std::size_t n) { return (*data)[n]; }
	const std::string& operator[](std::size_t n) const { return (*data)[n]; }

	size_type size()const { return data->size(); }
	bool empty()const { return data->empty(); }
	void push_back(const std::string& str);
	// 13.55
	void push_back(std::string&&);
	void pop_back();
	std::string& front();
	const std::string& front()const;
	std::string& back();
	std::string& back()const;
	ConstStrBlobPtr begin() const;
	ConstStrBlobPtr end() const;

private:
	std::shared_ptr<std::vector<std::string>> data;
	void check_size(size_type size, const std::string& str) const;
};

void StrBlob::check_size(size_type size, const std::string& str) const
{
	if (size >= data->size())
		throw std::out_of_range(str);
}


StrBlob::StrBlob(const StrBlob& rhs) {
	data = std::make_shared<std::vector<std::string>>(*(rhs.data));
}

StrBlob& StrBlob::operator=(const StrBlob& rhs)
{
	data = std::make_shared<std::vector<std::string>>(*(rhs.data));
	return *this;
}


void StrBlob::push_back(const std::string& str)
{
	data->push_back(str); 
}

void StrBlob::push_back(std::string&& str)
{
	data->push_back(std::move(str));
}

void StrBlob::pop_back()
{
	check_size(0, "pop_back on empty StrBlob");
	data->pop_back();
}

std::string& StrBlob::front()
{
	check_size(0, "front on empty StrBlob");
	return *(data->begin());
}

const std::string& StrBlob::front() const
{
	check_size(0, "const front on empty StrBlob");
	return data->front();
}

std::string& StrBlob::back()
{
	check_size(0, "back on empty StrBlob");
	return data->back();
}

std::string& StrBlob::back() const
{
	check_size(0, "const back on empty StrBlob");
	return data->back();
}

bool operator==(const StrBlob& lhs, const StrBlob& rhs)
{
	return lhs.data == rhs.data;
}

bool operator!=(const StrBlob& lhs, const StrBlob& rhs)
{
	return !(lhs == rhs);
}

bool operator<(const StrBlob& lhs, const StrBlob& rhs)
{
	return *(lhs.data) < *(rhs.data);
}

bool operator>(const StrBlob& lhs, const StrBlob& rhs)
{
	return *(lhs.data) > *(rhs.data);
}

bool operator<=(const StrBlob& lhs, const StrBlob& rhs)
{
	return *(lhs.data) <= *(rhs.data);
}

bool operator>=(const StrBlob& lhs, const StrBlob& rhs)
{
	return *(lhs.data) >= *(rhs.data);
}

class StrBlobPtr {
	// 14.6
	friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
	// 14.18
	friend bool operator<(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator>(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator<=(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator>=(const StrBlobPtr&, const StrBlobPtr&);
	// 14.28
	friend StrBlobPtr operator+(const StrBlobPtr& , std::size_t);
	friend StrBlobPtr operator-(const StrBlobPtr& , std::size_t);

public:
	StrBlobPtr() = default;
	StrBlobPtr(StrBlob& p, size_t sz = 0) :
		wptr(p.data), curr(sz) {};

	// 14.26
	std::string& operator[](std::size_t n) { return (*wptr.lock())[n]; }
	const std::string& operator[](std::size_t n) const { return (*wptr.lock())[n]; }
	// 14.26
	StrBlobPtr& operator++();
	StrBlobPtr& operator--();
	StrBlobPtr operator++(int);
	StrBlobPtr operator--(int);
	// 14.28
	StrBlobPtr& operator+=(std::size_t);
	StrBlobPtr& operator-=(std::size_t);
	// 14.30
	std::string& operator*() const;
	std::string* operator->() const;

	std::string& deref() const;
	StrBlobPtr& incr();

private:
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr = 0;

	std::shared_ptr<std::vector<std::string>>
		check(std::size_t i, const std::string& msg) const;
};

std::shared_ptr<std::vector<std::string>> 
StrBlobPtr::check(std::size_t i, const std::string& msg) const
{
	auto ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	else
		return ret;
}

std::string& StrBlobPtr::deref() const
{
	auto ret = check(curr, "dereference past end");
	return ret->at(curr);
}

StrBlobPtr& StrBlobPtr::incr()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

StrBlobPtr& StrBlobPtr::operator++()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

StrBlobPtr& StrBlobPtr::operator--()
{
	--curr;
	check(curr, "increment past end of StrBlobPtr");
	return *this;
}

StrBlobPtr StrBlobPtr::operator++(int)
{
	StrBlobPtr ret = *this;
	++* this;
	return ret;
}

StrBlobPtr StrBlobPtr::operator--(int)
{
	StrBlobPtr ret = *this;
	--* this;
	return ret;
}

StrBlobPtr& StrBlobPtr::operator+=(std::size_t n)
{
	check(curr, "increment past end of StrBlobPtr");
	curr += n;
	return *this;
}

StrBlobPtr& StrBlobPtr::operator-=(std::size_t n)
{
	curr -= n;
	check(curr, "increment past end of StrBlobPtr");
	return *this;
}

std::string& StrBlobPtr::operator*() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

std::string* StrBlobPtr::operator->() const
{
	return &this->operator*();
}

StrBlobPtr operator+(const StrBlobPtr& lhs, std::size_t n)
{
	auto ret = lhs;
	ret += n;
	return ret;
}

StrBlobPtr operator-(const StrBlobPtr& lhs, std::size_t n)
{
	auto ret = lhs;
	ret -= n;
	return ret;
}

bool operator==(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
	auto lp = lhs.wptr.lock();
	auto rp = rhs.wptr.lock();
	if (lp == rp)
		return (!lp || lhs.curr == rhs.curr);
	else
		return false;
}

bool operator!=(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
	return !(lhs == rhs);
}

bool operator<(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
	auto lp = lhs.wptr.lock();
	auto rp = rhs.wptr.lock();
	if (lp == rp)
	{
		if (!lp)
			return false;
		return (lhs.curr < rhs.curr);
	}
	else
		return false;
}

bool operator>(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
	return rhs < lhs;
}

bool operator<=(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
	return !(rhs < lhs);
}

bool operator>=(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
	return !(lhs < rhs);
}

class ConstStrBlobPtr {
public:
	ConstStrBlobPtr() = default;
	ConstStrBlobPtr(const StrBlob& p, size_t sz = 0) :
		wptr(p.data), curr(sz) {};

	// 14.30
	const std::string& operator*() const;
	const std::string* operator->() const;

	const std::string& deref() const;
	const std::string& deref(size_t sz) const;
	ConstStrBlobPtr& incr();
private:
	std::shared_ptr<std::vector<std::string>> check(std::size_t i, const std::string& msg) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr = 0;
};

std::shared_ptr<std::vector<std::string>> ConstStrBlobPtr::check(std::size_t i, const std::string& msg) const
{
	auto ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	else
		return ret;
}

const std::string& ConstStrBlobPtr::operator*() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

const std::string* ConstStrBlobPtr::operator->() const
{
	return &(this->operator*());
}


const std::string& ConstStrBlobPtr::deref() const
{
	auto ret = check(curr, "dereference past end");
	return ret->at(curr);
}

const std::string& ConstStrBlobPtr::deref(size_t sz) const
{
	auto ret = check(sz, "dereference past end");
	return ret->at(sz);
}

ConstStrBlobPtr& ConstStrBlobPtr::incr()
{
	auto ret = check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

ConstStrBlobPtr StrBlob::begin() const
{
	ConstStrBlobPtr p(*this, 0);
	return p;
}

ConstStrBlobPtr StrBlob::end() const
{
	ConstStrBlobPtr p(*this, data->size());
	return p;
}
