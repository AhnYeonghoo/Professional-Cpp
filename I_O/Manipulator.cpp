#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>

using namespace std;

int mainManipulator()
{
	// 부울값
	bool myBool{ true };
	cout << "This is the default: " << myBool << endl;
	cout << "This should be true: " << boolalpha << myBool << endl;
	cout << "This should be 1: " << noboolalpha << myBool << endl;

	// "%6d"와 같은 효과를 스트림에 적용하는 방법
	int i{ 123 };
	printf("This should be  '     123':, %6d\n", i);
	cout << "This should be '    123':  " << setw(6) << i << endl;

	// %06d와 같은 효과를 스트림에 적용하는 방법
	printf("This should be '000123': %06d\n", i);
	cout << "This should be '000123': " << setfill('0') << setw(6) << i << endl;
	
	// *로 채우기
	cout << "This should be '***123': " << setfill('*') << setw(6) << i << endl;
	// 빈칸 채우기 문자 리셋
	cout << setfill(' ');

	// 부동소수점수
	double dbl { 1.452 };
	double dbl2{ 5 };
	cout << "This should be ' 5': " << setw(2) << noshowpoint << dbl2 << endl;
	cout << "This should be @@1.452: " << setw(7) << setfill('@') << dbl << endl;
	// 빈칸 채우기 리셋
	cout << setfill(' ');

	// cout에서 숫자 포맷을 지역에 맞게 설정한다.
	// imbue() 메서드와 locale 객체는 19장
	cout.imbue(locale(""));

	// 현재 지역에 맞게 숫자를 표현한다.
	cout << "This is 1234567 formatted according to uour location: " << 1234567 << endl;

	// 화폐 금액을 표시한다. 정확한 액수는 현재 지역에 맞게 표현한다.
	cout << "This should be a monetary value of 120000, "
		<< "formatted according to your location: "
		<< put_money("120000") << endl;

	// 날짜와 시간
	time_t t_t{ time(nullptr) };
	tm* t{ localtime(&t_t) };
	cout << "This should be the current date and time "
		<< "formatted according to your location: "
		<< put_time(t, "%c") << endl;

	// 인용 부호로 묶은 스트림
	cout << "This should be: \"Quoted string with \\\"embedded quotes\\\".\": "
		<< quoted("Quoted string with \"embedded quotes\".") << endl;
	return 0;
}