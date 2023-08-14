#include <iostream>
#include <string>

using namespace std;

const std::string& getString() {
	return "Hello World";
}

void swap(int& first, int& second)
{
	int temp{ first };
	first = second;
	second = temp;
}

void printString(const std::string myString)
{
	cout << myString << endl;
}

int mainReference()
{
	int x{ 3 };
	int& xRef{ x };
	xRef = 10;

	cout << x << " " << xRef << endl;

	int y{ 4 };
	xRef = y;
	cout << x << " " << xRef << endl;
	
	int z;
	const int& zRef{ z };
	
	// 포인터에 대한 레퍼런스와 레퍼런스에 대한 포인터
	int* intP{ nullptr };
	int*& ptrRef{ intP };
	ptrRef = new int;
	*ptrRef = 5;
	cout << *ptrRef << " " << *intP << endl;

	int x2{ 3 };
	int& x2Ref{ x2};
	int* xPtr{ &x2Ref };
	*xPtr = 40;
	
	cout << *xPtr << " " << x2 <<  " " << x2Ref << endl;
	pair myPair{ "Hello", 5 };
	auto [theString, theInt] {myPair};
	cout << theString << " " << theInt << endl;

	int* xp{ &x }, * yp{ &y };
	cout << *xp << " " << *yp << endl;
	swap(*xp, *yp);
	cout << *xp << " " << *yp << endl;

	return 0;
}

class MyClass2
{
public:
	MyClass2(int& ref) : m_ref{ref} {}
private:
	int& m_ref;
};
