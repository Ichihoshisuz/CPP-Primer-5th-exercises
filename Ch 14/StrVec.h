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
	// 14.16
	friend bool operator==(const StrVec&, const StrVec&);
	friend bool operator!=(const StrVec&, const StrVec&);
	// 14.18
	friend bool operator<(const StrVec&, const StrVec&);
	friend bool operator<=(const StrVec&, const StrVec&);
	friend bool operator>(const StrVec&, const StrVec&);
	friend bool operator>=(const StrVec&, const StrVec&);
public:
	StrVec() :elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(const std::initializer_list<std::string>&);
	StrVec(const StrVec&);
	StrVec& operator=(const StrVec&);
	StrVec(StrVec&&) noexcept;
	StrVec& operator=(StrVec&&) noexcept;
	~StrVec();

	StrVec& operator=(const std::initializer_list<std::string>&);
	// 14.26
	std::string& operator[](std::size_t n) { return elements[n]; }
	const std::string& operator[](std::size_t n) const { return elements[n]; }

	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	std::string* begin() const { return elements; }
	std::string* end() const { return first_free; }
	void push_back(const std::string&);
	void resize(std::size_t);
	void resize(std::size_t, const std::string&);
	void reserve(std::size_t);

private:
	std::string* elements;
	std::string* first_free;
	std::string* cap;
	static std::allocator<std::string> alloc;

	void chk_n_alloc();
	std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
	void free();
	void reallocate(std::size_t);
};

std::allocator<std::string> StrVec::alloc;

void StrVec::chk_n_alloc()
{
	auto now_size = size();
	if (now_size == 0)
		// Ĭ�Ϸ����ĸ���Ԫ���ڴ档
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

	// for_each �� lambda д��
	if (elements)
	{
		auto dealloc = [](std::string& p) {alloc.destroy(&p); };
		std::for_each(elements, first_free, dealloc);
		alloc.deallocate(elements, cap - elements);
	}
}

void StrVec::reallocate(std::size_t new_capacity)
{
	// ����ռ�
	auto new_data = alloc.allocate(new_capacity);
	//�Ӿɿռ��ƶ����¿ռ�
	/*
	for (std::size_t i = 0; i < size(); ++i)
		alloc.construct(dest++, std::move(*src++));
	free();
	*/
	auto last = std::uninitialized_copy(std::make_move_iterator(begin()),
		std::make_move_iterator(end()), new_data);
	free();
	elements = new_data;
	first_free = last;
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

StrVec::StrVec(StrVec&& s) noexcept
	:elements(s.elements), first_free(s.first_free), cap(s.cap)
{
	s.elements = s.first_free = s.cap = nullptr;
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

StrVec& StrVec::operator=(StrVec&& rhs) noexcept
{
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
			alloc.construct(first_free++, str);
	else if (new_size < now_size)
		for (std::size_t i = 0; i < now_size - new_size; ++i)
			alloc.destroy(--first_free);
}

void StrVec::reserve(std::size_t new_capacity)
{
	auto now_capacity = capacity();
	// ��� reserve �Ĳ����ȵ�ǰ�� capacity С����ʲôҲ������
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


StrVec& StrVec::operator=(const std::initializer_list<std::string>& ini_list_str)
{
	auto new_data = alloc_n_copy(ini_list_str.begin(), ini_list_str.end());
	free();
	elements = new_data.first;
	first_free = new_data.second;
	cap = new_data.second;
	return *this;
}

bool operator==(const StrVec& lhs, const StrVec& rhs)
{
	if (lhs.size() != rhs.size())
		return false;

	for (auto src_lhs = lhs.begin(), src_rhs = rhs.begin();
		src_lhs != lhs.end(); ++src_lhs, ++src_rhs)
	{
		if (*src_lhs != *src_rhs)
			return false;
	}
	return true;
}

bool operator!=(const StrVec& lhs, const StrVec& rhs)
{
	return !(lhs == rhs);
}

bool operator<(const StrVec& lhs, const StrVec& rhs)
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

bool operator>(const StrVec& lhs, const StrVec& rhs)
{
	return rhs < lhs;
}

bool operator<=(const StrVec& lhs, const StrVec& rhs)
{
	return !(rhs < lhs);
}

bool operator>=(const StrVec& lhs, const StrVec& rhs)
{
	return !(lhs < rhs);
}