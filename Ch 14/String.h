#pragma once

#include <utility>
#include <memory>
#include <string>
#include <iostream>
#include <stdexcept>
#include <initializer_list>
#include <algorithm>

class String
{
	friend std::ostream& print(std::ostream&, String&);
	friend std::ostream& operator<<(std::ostream&, String&);
	// 14.16
	friend bool operator==(const String&, const String&);
	friend bool operator!=(const String&, const String&);
	// 14.18
	friend bool operator<(const String&, const String&);
	friend bool operator<=(const String&, const String&);
	friend bool operator>(const String&, const String&);
	friend bool operator>=(const String&, const String&);
public:
	String() :elements(nullptr), first_free(nullptr), cap(nullptr) {}
	String(const char*);
	String(const String&);
	String& operator=(const String&);
	String(String&&) noexcept;
	String& operator=(String&&) noexcept;
	~String();

	// 14.26
	char& operator[](std::size_t n) { return elements[n]; }
	const char& operator[](std::size_t n) const { return elements[n]; }

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

std::allocator<char> String::alloc;

void String::chk_n_alloc()
{
	auto now_size = size();
	if (now_size == 0)
		// Ĭ�Ϸ����ĸ���Ԫ���ڴ档
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

	// for_each �� lambda д��
	if (elements)
	{
		auto dealloc = [](char& p) {alloc.destroy(&p); };
		std::for_each(elements, first_free, dealloc);
		alloc.deallocate(elements, cap - elements);
	}
}

void String::reallocate(std::size_t new_capacity)
{
	// ����ռ�
	auto new_data = alloc.allocate(new_capacity);
	//�Ӿɿռ��ƶ����¿ռ�
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
	std::cout << "��ʱ���ÿ������캯��" << std::endl;
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = newdata.second;
	cap = newdata.second;
}

String& String::operator=(const String& rhs)
{
	std::cout << "��ʱ���ÿ�����ֵ����" << std::endl;
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = data.second;
	cap = data.second;
	return *this;
}

String::String(String&& s) noexcept :
	elements(s.elements), first_free(s.first_free), cap(s.cap)
{
	std::cout << "��ʱ�����ƶ����캯��" << std::endl;
	s.elements = s.first_free = s.cap = nullptr;
}

String& String::operator=(String&& rhs) noexcept
{
	std::cout << "��ʱ�����ƶ���ֵ����" << std::endl;
	if (this != &rhs)
	{
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
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
	// ��� resize() �� new_size Ϊ 0 ���ȼ��ڵ��� free() ���ͷ��ڴ档
	if (new_size == 0)
	{
		free();
		return;
	}
	if (new_size < 0)
	{
		throw std::runtime_error("resize ��ֵ�����Ǹ�����");
		return;
	}
	// ���ʱ���·���
	if (new_size == size())
		return;

	// ���� resize �Ĳ������ڵ�ǰ������ֻ�ǻ���� reserve()
	if (new_size > capacity())
		reserve(new_size);
	auto now_size = size();
	if (new_size > now_size)
		// �ٶ�����Ĭ�Ϲ���
		for (std::size_t i = 0; i < new_size - now_size; ++i)
			alloc.construct(first_free++, c);
	else
		for (std::size_t i = 0; i < now_size - new_size; ++i)
			alloc.destroy(--first_free);
}

void String::reserve(std::size_t new_capacity)
{
	auto now_capacity = capacity();
	// ��� reserve �Ĳ����ȵ�ǰ�� capacity С����ʲôҲ������
	if (now_capacity < new_capacity)
		reallocate(new_capacity);

}

std::ostream& print(std::ostream& os, String& str)
{
	for (auto p = str.elements; p != str.end(); ++p)
		std::cout << *p;
	return os;
}

std::ostream& operator<<(std::ostream& os, String& str)
{
	for (auto p = str.elements; p != str.end(); ++p)
		std::cout << *p;
	return os;
}

bool operator==(const String& lhs, const String& rhs)
{
	if (lhs.size() != rhs.size())
		return false;
	if (lhs.elements == nullptr && rhs.elements == nullptr)
		return true;

	for (auto src_lhs = lhs.begin(), src_rhs = rhs.begin();
		src_lhs != lhs.end(); ++src_lhs, ++src_rhs)
	{
		if (*src_lhs != *src_rhs)
			return false;
	}
	return true;
}

bool operator!=(const String& lhs, const String& rhs)
{
	return !(lhs == rhs);
}

bool operator<(const String& lhs, const String& rhs)
{
	// ���Ҳ�Ƚϵ���Ϊ��Сֵ��< ��Ϊ false
	if (rhs.elements == nullptr)
		return false;
	if (lhs.elements == nullptr)
		return true;

	for (auto src_lhs = lhs.begin(), src_rhs = rhs.begin();
		src_lhs != lhs.end() && src_rhs != rhs.end(); ++src_lhs, ++src_rhs)
	{
		if (*src_lhs < *src_rhs)
			return true;
		if (*src_lhs > *src_rhs)
			return false;
	}
	// �������ѭ��ʱ���бȽϹ���Ԫ�ض���ȣ���ô�ͱȽϳ���
	if (lhs.size() < rhs.size())
		return true;
	else
		return false;
}

bool operator>(const String& lhs, const String& rhs)
{
	return rhs < lhs;
}

bool operator<=(const String& lhs, const String& rhs)
{
	return !(rhs < lhs);
}

bool operator>=(const String& lhs, const String& rhs)
{
	return !(lhs < rhs);
}