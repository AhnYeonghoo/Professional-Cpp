#include <iostream>
#include <string>
#include <format>
using namespace std;

string readName(istream& stream)
{
	string name;
	while (stream) {
		int next{ stream.get() };
		if (!stream || next == std::char_traits<char>::eof()) break;
		name += static_cast<char>(next); // ���� �̾� ���̱�
	}
	return name;
}


// get()�� ����� �� ������ ���
string readName2(istream& stream)
{
	string name;
	char next;
	while (stream.get(next)) {
		name += next;
	}
	return name;
}

void getReservationData2()
{
	string guestName;
	int partySize{ 0 };
	// ���ڰ� ���� �� ���� ���ڸ� �д´�.
	char ch;
	cin >> noskipws;
	while (cin >> ch) {
		if (isdigit(ch)) {
			cin.unget();
			if (cin.fail()) {
				cout << "unget() failed" << endl;
			}
			break;
		}
		guestName += ch;
	}

	if (cin) {
		cin >> partySize;
	}
	if (!cin) {
		cerr << "Error getting party size." << endl;
		return;
	}

	cout << format("Thank you '{}', party of {}", guestName, partySize) << endl;
	if (partySize > 10) {
		cout << "An extra gratuity will apply." << endl;
	}

}

void getReservationDataPeek()
{
	string guestName;
	int partySize{ 0 };
	cin >> noskipws;
	while (true) {
		char ch{ static_cast<char>(cin.peek()) };
		if (!cin) break;
		if (isdigit(ch)) break;
		cin >> ch;
		if (!cin) break;
		guestName += ch;
	}

	if (cin) cin >> partySize;
	if (!cin) {
		cerr << "Error getting party size." << endl;
		return;
	}

	cout << format("Thank you '{}', party of {}", guestName, partySize) << endl;
	if (partySize > 10) {
		cout << "An extra gratuity will apply." << endl;
	}
}

int mainInputMethod()
{
	// getline() �޼���
	cout << "Enter multiple lines of text. "
		<< "Use an @ character to signal the end of the text.\n>";
	string myString;
	getline(cin, myString, '@');
	cout << format("Read text: \"{}\"", myString) << endl;

	return 0;
}