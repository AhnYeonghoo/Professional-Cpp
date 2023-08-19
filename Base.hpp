/*
* C++���� Ŭ������ ������ �� ���� Ŭ������ ����Ѵٰ� ������ �� �ִ�.
* �̋� ���� Ŭ������ �θ� Ŭ����, Ȯ���� Ŭ������ �ڽ� Ŭ������� �Ѵ�.
*/
#include <iostream>

class Base // ����Ŭ���� ����
{
public:
	Base() {}
	virtual ~Base() = default; // �Ҹ��ڴ� �ݵ��! virtual�� �����Ѵ�.
	 // virtual Ű���带 �ٿ��߸� override�� �����ϴ�.
	virtual void someMethod()
	{
		std::cout << "This is Base`s version of someMethod()" << std::endl;
	}
protected:
	int m_protectedInt{ 0 };
private:
	int m_privateInt{ 0 };
	
};

class Derived : public Base // ����Ŭ���� ����
{
public:
	Derived() {}
	virtual void someOtherMethod() 
	{
		std::cout << "I can access base class data member m_protectedInt. " << std::endl;
		std::cout << "Its value is " << m_protectedInt << std::endl;
		// private �ɹ��� �Ļ�Ŭ������ ������ �� ����.
	}

	void someMethod() override final // ���̻� �������̵� �Ұ����� final Ű����
	{
		std::cout << "This is Derived`s version of someMethond()" << std::endl;
	}
};

class Base2 final // final Ű����� ����� �����ϴ� Ű����
{};

class DerivedDerived : public Derived
{
public:
	// void someMethod() override {} -> Compile Error!
};