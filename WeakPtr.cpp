#include <iostream>
#include <memory>

using namespace std;

class Foo2 : public enable_shared_from_this<Foo2>
{
public:
	shared_ptr<Foo2> getPointer() {
		return shared_from_this();
	}
};

class Simple3
{
public:
	Simple3() { cout << "Constructor" << endl; }
	~Simple3() { cout << "Destructor" << endl; }
};

void useResource(weak_ptr<Simple3>& weakSimple);
unique_ptr<Simple3> create();

int main()
{
	auto sharedSimple{ make_shared<Simple3>() };
	weak_ptr<Simple3> weakSimple{ sharedSimple };
	
	useResource(weakSimple);
	
	// shared_ptr�� �����Ѵ�.
	// Simple ���ҽ��� ���� shared_ptr�� �ϳ� ���̹Ƿ�
	// weak_ptr�� ��� �ִ��� ���ҽ��� �����ȴ�.
	sharedSimple.reset();
	
	useResource(weakSimple);

	auto ptr1{ make_shared<Foo2>() };
	auto ptr2{ ptr1->getPointer() };
	

	return 0;
}

void useResource(weak_ptr<Simple3>& weakSimple)
{
	auto resource{ weakSimple.lock() };
	if (resource) cout << "Resource still alive" << endl;
	else cout << "Resource has been freed!" << endl;

}

unique_ptr<Simple3> create()
{
	auto ptr{ make_unique<Simple3>() };
	return ptr;
}