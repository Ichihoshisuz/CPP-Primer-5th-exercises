#include "StrBlob.h"
using namespace std;
class StrBlobPtr {
public:
	StrBlobPtr() = default;
	StrBlobPtr(StrBlob& p, size_t sz = 0) :
		wptr(p.data), curr(sz) {};
	std::string& deref() const;
	StrBlobPtr& incr();
private:
	std::shared_ptr<std::vector<std::string>> check(std::size_t i, const std::string& msg) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr = 0;
};

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t i, const std::string& msg) const
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
	auto ret = check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

class ConstStrBlobPtr {
public:
	ConstStrBlobPtr() = default;
	ConstStrBlobPtr(const StrBlob& p, size_t sz = 0) :
		wptr(p.data), curr(sz) {};
	std::string& deref() const;
	StrBlobPtr& incr();
private:
	std::shared_ptr<std::vector<std::string>> check(std::size_t i, const std::string& msg) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr = 0;
};

ConstStrBlobPtr StrBlob::begin() const
{
	ConstStrBlobPtr p{ *this,0 };
	return p;
}

ConstStrBlobPtr StrBlob::end() const
{
	ConstStrBlobPtr p{ *this,data->size() };
	return p;
}