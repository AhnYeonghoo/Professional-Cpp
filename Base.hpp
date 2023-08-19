/*
* C++에서 클래스를 정의할 때 기존 클래스를 상속한다고 선언할 수 있다.
* 이떄 원본 클래스를 부모 클래스, 확장한 클래스를 자식 클래스라고 한다.
*/
#include <iostream>

class Base // 슈퍼클래스 선언
{
public:
	Base() {}
	virtual ~Base() = default; // 소멸자는 반드시! virtual로 선언한다.
	 // virtual 키워드를 붙여야만 override가 가능하다.
	virtual void someMethod()
	{
		std::cout << "This is Base`s version of someMethod()" << std::endl;
	}
protected:
	int m_protectedInt{ 0 };
private:
	int m_privateInt{ 0 };
	
};

class Derived : public Base // 서브클래스 선언
{
public:
	Derived() {}
	virtual void someOtherMethod() 
	{
		std::cout << "I can access base class data member m_protectedInt. " << std::endl;
		std::cout << "Its value is " << m_protectedInt << std::endl;
		// private 맴버는 파생클래스라도 접근할 수 없다.
	}

	void someMethod() override final // 더이상 오버라이딩 불가능한 final 키워드
	{
		std::cout << "This is Derived`s version of someMethond()" << std::endl;
	}
};

class Base2 final // final 키워드는 상속을 방지하는 키워드
{};

class DerivedDerived : public Derived
{
public:
	// void someMethod() override {} -> Compile Error!
};