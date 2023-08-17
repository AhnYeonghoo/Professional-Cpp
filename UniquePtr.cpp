#include <memory>
#include <iostream>

using namespace std;

class Simple2;
void leaky2();
void notLeaky();
void notLeaky2();
class Foo;
int* myAlloc(int value);
void myFree(int* p);

int mainUniquePtr()
{
	notLeaky();
	notLeaky2();
	cout << endl << endl;
	
	auto myVariableSizedArray{ make_unique<int[]>(10) }; // c style �迭�� ����Ʈ �����ͷ� ����
	for (size_t i{ 0 }; i < 10; i++) {
		myVariableSizedArray[i] = i;
	}

	for (size_t i{ 0 }; i < 10; i++) {
		cout << myVariableSizedArray[i] << " ";
	}
	cout << endl;
	cout << endl;
	
	

	
	return 0;
}

class Simple2 
{
public:
	Simple2() { cout << "Constructor" << endl; }
	~Simple2() { cout << "Destructor" << endl; }
	void go() {};
};

void leaky2()
{
	Simple2* mySimplePtr{ new Simple2{} };
	mySimplePtr->go();
}

void notLeaky()
{
	auto mySimpleSmartPtr{ make_unique<Simple2>() };
	mySimpleSmartPtr->go();
}

void notLeaky2()
{
	unique_ptr<Simple2> mySimpleSmartPtr{ new Simple2{} };
	mySimpleSmartPtr.reset();
	mySimpleSmartPtr.reset(new Simple2{});
	Simple2* simple{ mySimpleSmartPtr.release() }; // �������� �����Ѵ�.
	delete simple;
	simple = nullptr; // ���� �޸𸮸� �������־�� �Ѵ�.
}

class Foo
{
public:
	Foo(unique_ptr<int> data) : m_data{ move(data) } {}
private:
	unique_ptr<int> m_data;
};

int* myAlloc(int value) { return new int{ value }; }
void myFree(int* p) { delete p; }