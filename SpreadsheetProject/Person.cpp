#include "Person.hpp"
#include <iostream>
using namespace std;

void performTask()
{
	static bool initialized{ false };
	if (!initialized) {
		cout << "Initializing!" << endl;
		initialized = true;
	}
}

int mainPerson()
{
	Person person{ "Kole", "Webb" };
	cout << person.getLastName() << ", " << person.getFirstName() << endl;

	return 0;
}