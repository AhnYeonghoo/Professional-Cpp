#include <cstdio>
#include <cstdarg>
#include <iostream>
using namespace std;

bool debug{ false };

void debugOut(const char* str, ...)
{
	va_list ap;
	if (debug) {
		va_start(ap, str);
		vfprintf(stderr, str, ap);
		va_end(ap);
	}
}

void printInts(size_t num, ...)
{
	va_list ap;
	va_start(ap, num);
	for (size_t i{ 0 }; i < num; i++) {
		int tmp{ va_arg(ap, int) };
		cout << tmp << " ";
	}
	va_end(ap);
	cout << endl;
}

int mainCUtiliy()
{
	debug = true;
	debugOut("int %d\n", 5);
	debugOut("String %s and int %d\n", "hello", 5);
	debugOut("Many ints: %d, %d, %d, %d ,%d \n", 1, 2, 3, 4, 5);
	return 0;
}