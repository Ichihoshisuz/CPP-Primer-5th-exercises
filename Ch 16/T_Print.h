#pragma once

#include <iostream>

template <typename T, std::size_t N>
void print(const T(&v)[N])
{
	for (std::size_t i = 0; i < N; ++i)
		std::cout << v[i] << std::endl;
	std::cout << std::endl;
}