#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

class HasPtr
{
	friend void swap(HasPtr& lhs, HasPtr& rhs);
public:
	HasPtr(const string& s = string()) :
		ps(new string(s)), i(0) { }
 
	HasPtr(const HasPtr& s);

	HasPtr& operator=(const HasPtr& s);

	string& operator*();
	
	bool operator<(const HasPtr& rhs) const;

	~HasPtr() {
		delete ps;
	}
private:
	string* ps;
	int i;
};


HasPtr::HasPtr(const HasPtr& s)
{
	ps = new string(*s.ps);
	i = s.i;
}


string& HasPtr::operator*()
{
	return *ps;
}


HasPtr& HasPtr::operator=(const HasPtr& s)
{
	auto new_ps = new string(*s.ps);
	delete ps;
	ps = new_ps;
	i = s.i;
	return *this;	//这样就可以保证连等了
}


bool HasPtr::operator<(const HasPtr& rhs) const   //需要注意这里是const比较好。
{
	return *ps < *rhs.ps;
}


inline
void swap(HasPtr& lhs, HasPtr& rhs)
{
	using std::swap;
	cout << "调用HasPtr的swap函数" << endl;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}