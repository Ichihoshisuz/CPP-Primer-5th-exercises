#pragma once

#include <utility>
#include <memory>
#include <string>
#include <iostream>
#include <stdexcept>
#include <initializer_list>
#include <algorithm>

class StrVec
{
	friend std::ostream& print(std::ostream& os, StrVec& str);
public:
	StrVec() :elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(const std::initializer_list<std::string>&);
	StrVec(const StrVec&);
	StrVec& operator=(const StrVec&);
	~StrVec();

	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	std::string* begin() const { return elements; }
	std::string* end() const { return first_free; }
	void push_back(const std::string&);
	void resize(std::size_t); 
	void resize(std::size_t, const std::string&);
	void reserve(std::size_t);

private:
	static std::allocator<std::string> alloc;
	std::string* elements;
	std::string* first_free;
	std::string* cap;
	
	void chk_n_alloc();
	std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
	void free();
	void reallocate(std::size_t);
};

void StrVec::chk_n_alloc()
{
	auto now_size = size();
	if (now_size == 0)
		// 默认分配四个单元的内存。
		reallocate(4);
	else if (now_size == capacity())
		reallocate(2 * now_size);
}

std::pair<std::string*, std::string*> 
	StrVec::alloc_n_copy(const std::string* b, const std::string* e)
{
	auto data = alloc.allocate(e - b);
	return { data, std::uninitialized_copy(b, e, data) };
}

void StrVec::free()
{
	/*
	if (elements)
	{
		for (auto p = first_free; p != elements;)
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
    */

	// for_each 和 lambda 写法
	if (elements)
	{
		auto dealloc = [](std::string& p) {alloc.destroy(&p); };
		std::for_each(elements, first_free, dealloc);
		alloc.deallocate(elements, cap - elements);
	}
}

void StrVec::reallocate(std::size_t new_capacity)
{
	// 分配空间
	auto new_data = alloc.allocate(new_capacity);
	//从旧空间移动到新空间
	auto src = elements;
	auto dest = new_data;
	for (std::size_t i = 0; i < size(); ++i)
		alloc.construct(dest++, std::move(*src++));
	free();
	elements = new_data;
	first_free = dest;
	cap = new_data + new_capacity;
}

StrVec::StrVec(const std::initializer_list<std::string>& ini_list_str) 
{
	auto new_data = alloc_n_copy(ini_list_str.begin(), ini_list_str.end());
	elements = new_data.first;
	first_free = new_data.second;
	cap = new_data.second;
}

StrVec::StrVec(const StrVec& s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = newdata.second;
	cap = newdata.second;
}

StrVec& StrVec::operator=(const StrVec& rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = data.second;
	cap = data.second;
	return *this;
}

StrVec::~StrVec()
{
	free();
}

void StrVec::push_back(const std::string& str)
{
	chk_n_alloc();
	alloc.construct(first_free++, str);
}

void StrVec::resize(std::size_t new_size)
{
	resize(new_size, "");
}

void StrVec::resize(std::size_t new_size, const std::string& str)
{
	if (new_size < 0)
	{
		throw std::runtime_error("resize 的值不该是个负数");
		return;
	}

	auto now_size = size();
	if (new_size > now_size)
		// 假定采用默认构造
		for (std::size_t i = 0; i < new_size - now_size; ++i)
			alloc.construct(first_free++, str);
	else if (new_size < now_size)
		for (std::size_t i = 0; i < now_size - new_size; ++i)
			alloc.destroy(--first_free);
}

void StrVec::reserve(std::size_t new_capacity)
{
	auto now_capacity = capacity();
	// 如果 reserve 的参数比当前的 capacity 小，则什么也不做。
	if (now_capacity < new_capacity)
		reallocate(new_capacity);

}

std::ostream& print(std::ostream& os, StrVec& str)
{
	for (auto p = str.elements; p != str.end(); ++p)
		std::cout << *p << std::endl;
	std::cout << std::endl;
	return os;
}

std::allocator<std::string> StrVec::alloc;