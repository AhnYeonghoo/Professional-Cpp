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
	// 되도록 새프로젝트에선 C Style 캐스팅을 지양하고 C++ Style 캐스팅을 사용하도록 한다.

	// 클래스의 캐스팅
	Base4* b{ nullptr };
	Derived4* d{ new Derived4 };
	b = d; // 상속 계층의 상위 타입으로 업캐스트할 필요 없다.
	d = static_cast<Derived4*>(b); // 다운캐스트 할 때는 명시적으로 캐스팅 해주어야 한다.
	
	Base4 base;
	Derived4 derived;
	Base4& br{ derived };
	Derived4& dr{ static_cast<Derived4&>(br) };
	return 0;
}