#pragma once

#include <utility>
#include <memory>
#include <string>
#include <iostream>
#include <stdexcept>
#include <initializer_list>
#include <algorithm>

// 没做测试
class String
{
	friend std::ostream& print(std::ostream& os, String& str);
public:
	String() :elements(nullptr), first_free(nullptr), cap(nullptr) {}
	String(const char*);
	String(const String&);
	String& operator=(const String&);
	~String();

	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	char* begin() const { return elements; }
	char* end() const { return first_free; }
	void push_back(char);
	void resize(std::size_t);
	void resize(std::size_t, char);
	void reserve(std::size_t);

private:
	static std::allocator<char> alloc;
	char* elements;
	char* first_free;
	char* cap;

	void chk_n_alloc();
	std::pair<char*, char*> alloc_n_copy(char*, char*);
	void free();
	void reallocate(std::size_t);
};

void String::chk_n_alloc()
{
	auto now_size = size();
	if (now_size == 0)
		// 默认分配四个单元的内存。
		reallocate(4);
	else if (now_size == capacity())
		reallocate(2 * now_size);
}

std::pair<char*, char*>
String::alloc_n_copy(char* b, char* e)
{
	auto data = alloc.allocate(e - b);
	return { data, std::uninitialized_copy(b, e, data) };
}

void String::free()
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
		auto dealloc = [](char& p) {alloc.destroy(&p); };
		std::for_each(elements, first_free, dealloc);
		alloc.deallocate(elements, cap - elements);
	}
}

void String::reallocate(std::size_t new_capacity)
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

String::String(const char* str)
{
	if (str != nullptr)
	{
		std::size_t b = 0;
		std::size_t e = strlen(str);
		elements = alloc.allocate(e - b);
		char* data = elements;
		while (b != e)
			alloc.construct(data++, str[b++]);
		first_free = data;
		cap = data;
	}
	else
	{
		elements = nullptr;
		first_free = nullptr;
		cap = nullptr;
	}
}

String::String(const String& s)
{
	std::cout << "此时调用拷贝构造函数" << std::endl;
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = newdata.second;
	cap = newdata.second;
}

String& String::operator=(const String& rhs)
{
	std::cout << "此时调用拷贝赋值函数" << std::endl;
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = data.second;
	cap = data.second;
	return *this;
}

String::~String()
{
	free();
}

void String::push_back(char c)
{
	chk_n_alloc();
	alloc.construct(first_free++, c);
}

void String::resize(std::size_t new_size)
{
	resize(new_size, '\0');
}

void String::resize(std::size_t new_size, char c)
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
			alloc.construct(first_free++, c);
	else if (new_size < now_size)
		for (std::size_t i = 0; i < now_size - new_size; ++i)
			alloc.destroy(--first_free);
}

void String::reserve(std::size_t new_capacity)
{
	auto now_capacity = capacity();
	// 如果 reserve 的参数比当前的 capacity 小，则什么也不做。
	if (now_capacity < new_capacity)
		reallocate(new_capacity);

}

std::ostream& print(std::ostream& os, String& str)
{
	for (auto p = str.elements; p != str.end(); ++p)
		std::cout << *p << std::endl;
	std::cout << std::endl;
	return os;
}

std::allocator<char> String::alloc;