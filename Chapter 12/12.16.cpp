#include <iostream>
#include <memory>
using namespace std;
int main()
{
	unique_ptr<int> ui(new int(42));
	return 0;
}