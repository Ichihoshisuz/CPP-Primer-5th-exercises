#include <iostream>
#include <list>
#include <forward_list>
using namespace std;
int main()
{
	list<int> ilist = { 12,3,43,245,3,6,456,4,746,76,764,890 };
	forward_list<int> iflist = { 123,52,5,36,6,43,898,232,34 };
	auto ilist_beg = ilist.begin();
	auto iflist_beg = iflist.begin();
	auto prev = iflist.before_begin();
	while (ilist_beg != ilist.end()) {
		if (*ilist_beg & 1) {
			ilist_beg = ilist.insert(ilist_beg, *ilist_beg);
			++ilist_beg;
			++ilist_beg;
		}
		else
			ilist_beg = ilist.erase(ilist_beg);
	}
	while (iflist_beg != iflist.end()) {
		if (*iflist_beg & 1) {
			iflist_beg=iflist.insert_after(prev, *iflist_beg);
			++iflist_beg;
			++iflist_beg;
			++prev;
			++prev;
		}
		else
			iflist_beg = iflist.erase_after(prev);
	}
	for (auto c : ilist)
		cout << c << " ";
	cout << endl;
	for (auto c : iflist)
		cout << c << " ";
	cout << endl;
	return 0;
}