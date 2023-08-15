#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

char* copyString(const char* str)
{
	char* result{ new char[strlen(str) + 1] };
	strcpy(result, str);
	return result;
}

char* appendString(const char* str1, const char* str2, const char* str3)
{
	char* result{ new char[strlen(str1) + strlen(str2) + strlen(str3) + 1] };
	strcpy(result, str1);
	strcpy(result, str2);
	strcpy(result, str3);
	return result;
}

int mainCStyleString()
{
	char text1[]{ "abcdef" }; // 스트링의 길이는 6글자
	cout << strlen(text1) << endl; // 6이 출력
	cout << sizeof(text1) << endl; // 7이 출력

	const char* text2{ "abcdef" };
	cout << strlen(text2) << endl;
	cout << sizeof(text2) << endl;

	cout << "Hello World" << endl; // String Literal

	const char* str{ R"(Hello "World"!)" }; // Raw String Literal
	const string str2{ R"(Hello World:::""")" };
	cout << str << " " << str2 << endl;
	const char* str3{ R"(Line1
		Line2)" };
	cout << str3 << endl;
	const char* str4{ R"(Is the following a tab character? \t)" };
	cout << str4 << endl;


	return 0;
}