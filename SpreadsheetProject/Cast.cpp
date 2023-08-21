#include <iostream>
using namespace std;

class Base4
{
public:
	virtual ~Base4() = default;
};

class Derived4 : public Base4
{
public:
	virtual ~Derived4() = default;
};

int mainCast()
{
	int i{ 3 };
	int j{ 4 };
	double result{ static_cast<double>(i) / j }; 
	// �ǵ��� ��������Ʈ���� C Style ĳ������ �����ϰ� C++ Style ĳ������ ����ϵ��� �Ѵ�.

	// Ŭ������ ĳ����
	Base4* b{ nullptr };
	Derived4* d{ new Derived4 };
	b = d; // ��� ������ ���� Ÿ������ ��ĳ��Ʈ�� �ʿ� ����.
	d = static_cast<Derived4*>(b); // �ٿ�ĳ��Ʈ �� ���� ��������� ĳ���� ���־�� �Ѵ�.
	
	Base4 base;
	Derived4 derived;
	Base4& br{ derived };
	Derived4& dr{ static_cast<Derived4&>(br) };
	return 0;
}