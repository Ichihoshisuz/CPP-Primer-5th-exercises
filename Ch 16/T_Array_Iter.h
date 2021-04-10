#pragma once

template <typename T, size_t N>
inline const T* begin(const T (&a)[N])
{
	return a;
}

template <typename T, size_t N>
inline const T* end(const T(&a)[N])
{
	return a + N;
}
