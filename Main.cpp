#include "Base.hpp"
using namespace std;

class BaseTest
{
public:
	BaseTest() { cout << "1"; }
	virtual ~BaseTest() { cout << "1"; }
};

class Something
{
public:
	Something() { cout << "2"; }
	virtual ~Something() { cout << "2"; }
};

class DerivedTest : public BaseTest
{
public:
	DerivedTest() { cout << "3"; }
	virtual ~DerivedTest() { cout << "3"; }
private:
	Something m_dataMember;
};


int main()
{
	Derived myD;
	myD.someMethod();
	myD.someOtherMethod();
	
	Base* base = { new Derived }; // 서브 객체를 생성하여 슈퍼 클래스 포인터에 저장.
	// 부모는 자식을 품을 수 있다!
	delete base;
	base = nullptr;
	
	cout << endl << endl;

	Base base1;
	base1.someMethod();
	Derived derived1;
	derived1.someMethod();
	
	Base& ref{ derived1 };
	ref.someMethod();
	
	Derived myDerived;
	Base assignedObject{ myDerived }; 
	assignedObject.someMethod();

	cout << endl << endl;
	
	DerivedTest derivedTest;
	// 1, 2, 3 순서로 생성
	// 3, 2, 1 순서로 소멸
	return 0;
}