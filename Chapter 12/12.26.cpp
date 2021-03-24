#include <iostream>
#include <string>
#include <memory>
#include <cstring>
using namespace std;
int main()
{
	allocator<char> ac;
	string words;
	while (cin >> words)
	{
		auto const p = ac.allocate(words.size());
		auto q = p;
		for (auto& c : words)
			ac.construct(q++, c);
		for (auto r = p; r != q; ++r)
			cout << *r;
		cout << endl;
		while (q != p)
			ac.destroy(--q);
		ac.deallocate(p, words.size());
	}
	return 0;
}