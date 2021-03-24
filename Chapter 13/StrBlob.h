#include <string>
#include <vector>
#include <memory>
#include <stdexcept>
class StrBlobPtr;
class ConstStrBlobPtr;
class StrBlob
{
public:
	friend class StrBlobPtr;
	friend class ConstStrBlobPtr;

	using size_type=std::vector<std::string>::size_type;

	StrBlob() :data(std::make_shared<std::vector<std::string>>()) {}
	StrBlob(std::initializer_list<std::string>& il) :
		data(std::make_shared <std::vector<std::string>>(il)) {}
	explicit StrBlob(std::shared_ptr<std::vector<std::string>>& sptr) :
		data(sptr) {}

	StrBlob(const StrBlob& rhs)
	{
		data = std::make_shared<std::vector<std::string>>(*(rhs.data));
	}

	StrBlob& operator=(const StrBlob& rhs)
	{
		data = std::make_shared<std::vector<std::string>>(*(rhs.data));
		return *this;
	}

	size_type size()const
	{
		return data->size();
	}
	bool empty()const
	{
		return data->empty();
	}
	void push_back(const std::string& str)
	{
		data->push_back(str);
	}
	void pop_back();
	std::string& front();
	const std::string& front()const;
	std::string& back();
	std::string& back()const;
	ConstStrBlobPtr begin() const;
	ConstStrBlobPtr end() const;

private:
	std::shared_ptr<std::vector<std::string>> data;
	void check_size(size_type size, const std::string& str)const;
};

void StrBlob::check_size(size_type size, const std::string& str)const
{
	if (size >= data->size())
		throw std::out_of_range(str);
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
const std::string& StrBlob::front()const
{
	check_size(0, "const front on empty StrBlob");
	return data->front();
}
std::string& StrBlob::back()
{
	check_size(0, "back on empty StrBlob");
	return data->back();
}
std::string& StrBlob::back()const
{
	check_size(0, "const back on empty StrBlob");
	return data->back();
}


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
	ConstStrBlobPtr p{ *this,0 };
	return p;
}

ConstStrBlobPtr StrBlob::end() const
{
	ConstStrBlobPtr p{ *this,data->size() };
	return p;
}
