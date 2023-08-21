#include <iostream>
using namespace std;

// dynamic_cast()�� ���� ��ü�� Ÿ�� ������ ���� �ð��� �˻��Ѵ�.

class Base5
{
public:
	virtual ~Base5() = default;
};

class Derived5 : public Base5
{
public:
	virtual ~Derived5() = default;
};

int mainDynamicCast()
{
	// �ùٸ� ���
	Base5* b;
	Derived5* d{ new Derived5{} };
	b = d;
	d = dynamic_cast<Derived5*>(b);

	return 0;

	// ���� �߻� ��Ȳ
	Base5 base;
	Derived5 derived;
	Base5& br{ base };
	try {
		Derived5& dr{ dynamic_cast<Derived5&>(br) };
	}
	catch (const bad_cast&) {
		cout << "Bad Cast!" << endl;
	}

	return 0;

}