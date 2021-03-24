#include <iostream> 
int main()
{   /*
	int i = 0, &r = i;
	auto a = r;
	const int ci = i, &cr = ci;
	auto b = ci;
	auto c = cr;
	auto d = &i;
	auto e = &ci;
	auto &g = ci;
	std::cout << a << " " << b << " " << c << " " << d << " " << e << " " << g << std::endl;


	//Á·Ï°2.33ÓëÁ·Ï°2.34

	a = 42;
	b = 42;
	c = 42;
	//d = 42;
	//e = 42;
	//g = 42;

	//Á·Ï°2.35
	*/
	const int i = 42;
	auto j = i; const auto &k = i; auto *p = &i;
	const auto j2 = i, &k2 = i;
	std::cout << typeid(i).name() << std::endl;
	std::cout << typeid(j2).name() << std::endl;
	std::cout << typeid(k2).name()<< std::endl;
	system("pause");
	return 0;
}