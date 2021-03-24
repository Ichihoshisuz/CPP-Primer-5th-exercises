#include <iostream>
#include <vector>
#include <deque>
#include <iterator>
#include <algorithm>
using namespace std;
int main()
{
	vector<int> vi{ 1,2,3,4,5,6,7,8,9,10 };
	vector<int> vi1, vi3;
	deque<int> vi2;
	copy(vi.cbegin(), vi.cend(), back_inserter(vi1));
	copy(vi.cbegin(), vi.cend(), front_inserter(vi2));
	copy(vi.cbegin(), vi.cend(), inserter(vi3,vi3.begin())); 
	for (auto c : vi1)
		cout << c << " ";
	cout << endl;
	for (auto c : vi2)
		cout << c << " ";
	cout << endl;
	for (auto c : vi3)
		cout << c << " ";
	cout << endl;

}