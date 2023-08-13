#include <iostream>

struct MyEmployee
{
	char firstInitial;
	char lastInitial;
	int employeeNumber;
	int salary{ 75'000 };
};

int mainDesignatedinitializer()
{
	// 지정초기화 사용
	MyEmployee anE{
		.firstInitial = 'J',
		.lastInitial = 'D',
		.salary = 80'000
	};
	return 0;
}