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
	// �����ʱ�ȭ ���
	MyEmployee anE{
		.firstInitial = 'J',
		.lastInitial = 'D',
		.salary = 80'000
	};
	return 0;
}