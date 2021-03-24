#include <iostream>
#include <vector>
#include <new>
using namespace std;
vector<int>* newvector() 
{
	vector<int>* vi = new vector<int>();
	return vi;
}
vector<int>* input_vector(vector<int>* vi)
{
	int i;
	while (cin >> i)
		vi->push_back(i);
	return vi;
}
void output_vector(vector<int>* vi)
{
	for (auto c : *vi)
	{
		cout << c << " ";
	}
	delete vi;
}
int main()
{
	vector<int>* vi = newvector();
	vi = input_vector(vi);
	output_vector(vi);
	vi = nullptr;
	return 0;
}