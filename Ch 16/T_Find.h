#pragma once

template <typename Iter, typename T>
Iter T_find(Iter beg, Iter end, const T& val)
{
	auto p = beg;
	while (p != end && *p != val)
		++p;
	return p;
}