#include <iostream>
int main()
{//作业2.18
	int a = 1;
	int *p = &a;
	std::cout << p << std::endl;
	int b = 2;
	p = &b;
	std::cout << *p << std::endl;
	std::cout << p << std::endl;
	*p = 0;
	
	std::cout << b << std::endl;
	system("pause");
	//作业2.20
	int i = 42;
	int*p1 = &i;
	*p1 = *p1 * *p1;
	std::cout << i << std::endl;
	
	//作业2.23吧
	int*c;
		if (c)
			std::cout << "c pass" << std::endl;
	system("pause");
	return 0;

	

}
