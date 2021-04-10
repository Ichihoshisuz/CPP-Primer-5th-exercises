#pragma once

template <typename T, size_t N>
inline constexpr size_t arr_size(const T(&a)[N])
{
	return N;
}

