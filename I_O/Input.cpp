#include <iostream>
#include <string>
using namespace std;

void getReservationData();

int mainInput()
{
	// 입력 받는 기초 방법
	string userInput;
	cin >> userInput;
	cout << "User input was: " << userInput << endl;
	// 또는 get() 함수를 사용

	return 0;
}

void getReservationData()
{
	string guestName;
	int partySize;
	cout << "Name and number of guests: ";
	cin >> guestName >> partySize;
	cout << "Thank you, " << guestName << "." << endl;
	if (partySize > 10) {
		cout << "An extra gratuity will apply." << endl;
	}
}