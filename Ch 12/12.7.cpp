#include <iostream>
#include <vector>
#include <memory>
using namespace std;
shared_ptr<vector<int>> newvector()
{
	shared_ptr<vector<int>> spi = make_shared<vector<int>>();
	return spi;
}
void input_vector(shared_ptr<vector<int>> spi)
{
	int i;
	while (cin >> i)
		spi->push_back(i);
}
void output_vector(shared_ptr<vector<int>> spi)
{
	for (auto c : *spi)
		cout << c << " ";
}
int main()
{
	shared_ptr<vector<int>> spi = newvector();
	input_vector(spi);
	output_vector(spi);
	return 0;
}