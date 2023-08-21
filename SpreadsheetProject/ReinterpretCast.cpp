#include <iostream>

using namespace std;

class X{};
class Y{};

int mainReinterpretCast()
{
	X x;
	Y y;
	X* xp{ &x };
	Y* yp{ &y };
	
	// 서로 관련없는 클래스 타입의 포인터를 변환할 때는 reinterpret_cast<>()를 사용해야 한다.
	// static_cast는 작동하지 않는다.
	xp = reinterpret_cast<X*>(yp);
	void* p{ xp };
	X& xr{ x };
	Y& yr{ reinterpret_cast<Y&>(x) };

	return 0;
}