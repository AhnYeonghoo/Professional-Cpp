#include <iostream>
#include <string>
using namespace std;

void getReservationData();

int mainInput()
{
	// �Է� �޴� ���� ���
	string userInput;
	cin >> userInput;
	cout << "User input was: " << userInput << endl;
	// �Ǵ� get() �Լ��� ���

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