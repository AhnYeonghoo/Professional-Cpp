#include <iostream>
#include <string>
using namespace std;


void thirdPartyLibraryMethod(char* str)
{
	/*dd*/
}

void f(const char* str)
{
	thirdPartyLibraryMethod(const_cast<char*>(str));
}

int mainConstCast()
{
	std::string str{ "C++" };
	const std::string& constStr{ as_const(str) };

	return 0;
}