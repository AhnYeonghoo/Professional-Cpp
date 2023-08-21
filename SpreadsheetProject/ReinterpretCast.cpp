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
	
	// ���� ���þ��� Ŭ���� Ÿ���� �����͸� ��ȯ�� ���� reinterpret_cast<>()�� ����ؾ� �Ѵ�.
	// static_cast�� �۵����� �ʴ´�.
	xp = reinterpret_cast<X*>(yp);
	void* p{ xp };
	X& xr{ x };
	Y& yr{ reinterpret_cast<Y&>(x) };

	return 0;
}