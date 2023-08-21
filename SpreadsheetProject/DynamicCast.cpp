#include <iostream>
using namespace std;

// dynamic_cast()는 내부 객체의 타입 정보를 실행 시간에 검사한다.

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
	// 올바른 사용
	Base5* b;
	Derived5* d{ new Derived5{} };
	b = d;
	d = dynamic_cast<Derived5*>(b);

	return 0;

	// 예외 발생 상황
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