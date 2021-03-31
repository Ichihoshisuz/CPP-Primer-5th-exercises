#pragma once
#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

class HasPtr
{
	friend void swap(HasPtr& lhs, HasPtr& rhs);
public:
	HasPtr(const string& s = string()) :ps(new string(s)), i(0) {};
	HasPtr(const HasPtr& s);
	HasPtr& operator=(const HasPtr&);
	HasPtr(HasPtr&&) noexcept;
	HasPtr& operator=(HasPtr&&) noexcept;

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


HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
	
	auto new_ps = new string(*rhs.ps);
	delete ps;
	ps = new_ps;
	i = rhs.i;
	return *this;	//�����Ϳ��Ա�֤������
	
	//�� 13.54 ������
	/*
	swap(*this, rhs);
	return *this;
	*/
}

HasPtr::HasPtr(HasPtr&& p) noexcept :ps(p.ps), i(p.i)
{
	p.ps = nullptr;
}

HasPtr& HasPtr::operator=(HasPtr&& rhs) noexcept
{
	if (this != &rhs)
	{
		delete ps;
		ps = rhs.ps;
		i = rhs.i;
		rhs.ps = nullptr;
	}
	return *this;
}

bool HasPtr::operator<(const HasPtr& rhs) const   //��Ҫע��������const�ȽϺá�
{
	return *ps < *rhs.ps;
}


inline void swap(HasPtr& lhs, HasPtr& rhs)
{
	using std::swap;
	cout << "����HasPtr��swap����" << endl;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}