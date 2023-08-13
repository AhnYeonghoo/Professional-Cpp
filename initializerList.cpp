#include <initializer_list>
#include <iostream>
#include <string>
#include <format>
using namespace std;

int makeSum(initializer_list<int> values)
{
	int total{ 0 };
	for (int value : values) {
		total += value;
	}
	return total;
}

int maininitializerList()
{
	int a{ makeSum({1, 2, 3}) };
	int b{ makeSum({10, 20, 30, 40, 50, 60}) };
	cout << a << endl;
	cout << b << endl;

	string myString{ "Hello World" };
	cout << format("The value myString is {}", myString) << endl;
	cout << format("The second letter is {}", myString[1]) << endl;
	return 0;
}