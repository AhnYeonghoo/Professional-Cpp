#include <iostream>
#include <format>
using namespace std;

void myFunction(int i, char c);

auto addNumbers(int number1, int number2)
{
	return number1 + number2;
}

void myLogFunction()
{
	cout << "Entering function" << __func__ << endl;
	return;
}

int mainFunction()
{
	myFunction(8, 'a');
	int someInt{ 3 };
	myFunction(someInt, 'b');

	myLogFunction();

	return 0;
}

void myFunction(int i, char c)
{
	std::cout << format("the value of i is {}", i) << std::endl;
	std::cout << format("the value of c is {}", c) << std::endl;
}