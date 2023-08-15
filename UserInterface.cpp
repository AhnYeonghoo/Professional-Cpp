#include <iostream>
#include <stdexcept>
#include <exception>
#include <format>
#include <string>
#include "Database.hpp"


using namespace std;
using namespace Records;

int displayMenu();
void doHire(Database& db);
void doFire(Database& db);
void doPromote(Database& db);

int mainUserInterface()
{
	Database employeeDB;
	bool done{ false };

	while (!done) {
		int selection{ displayMenu() };
		switch (selection) {
		case 0:
			done = true;
			break;
		case 1:
			doHire(employeeDB);
			break;
		case 2:
			doFire(employeeDB);
			break;
		case 3:
			doPromote(employeeDB);
			break;
		case 4:
			employeeDB.displayAll();
			break;
		case 5:
			employeeDB.displayCurrent();
			break;
		case 6:
			employeeDB.displayFormer();
			break;
		default:
			cerr << "Unknown command." << endl;
			break;
		}
	}

	return 0;
}

int displayMenu()
{
	int selection;
	cout << endl;
	cout << "Employee Database" << endl;
	cout << "-----------------" << endl;
	cout << "1) Hire a new employee" << endl;
	cout << "2) Fire an employee" << endl;
	cout << "3) Promote an employee" << endl;
	cout << "4) List all employees" << endl;
	cout << "5) List all current employees" << endl;
	cout << "6) List all former employees" << endl;
	cout << "0) Quit" << endl;
	cout << endl;
	cout << "--->";
	cin >> selection;
	return selection;
}

void doHire(Database& db)
{
	string firstName, lastName;
	cout << "firstName? ";
	cin >> firstName;
	
	cout << "lastname? ";
	cin >> lastName;
	
	auto& employee{ db.addEmployee(firstName, lastName) };
	cout << format("Hired Employee {} {} with employee number {}.",
		firstName, lastName, employee.getEmployeeNumber()) << endl;
}

void doFire(Database& db)
{
	int employeeNumber;
	cout << "Employee Number? ";
	cin >> employeeNumber;
	
	try {
		auto& emp{ db.getEmployee(employeeNumber) };
		emp.fire();
		cout << format("Employee {} terminated.", employeeNumber) << endl;
	}
	catch (const std::logic_error& exception) {
		cerr << format("Unable to terminate employee: {}",
			exception.what()) << endl;
	}
}

void doPromote(Database& db)
{
	int employeeNumber;
	cout << "Employee number? ";
	cin >> employeeNumber;
	
	int raiseAmount;
	cout << "How much of a raise? ";
	cin >> raiseAmount;
	
	try {
		auto& emp{ db.getEmployee(employeeNumber) };
		emp.promote(raiseAmount);
	}
	catch (const std::logic_error& exception) {
		cerr << format("Unable to promote employee: {}", exception.what()) << endl;
	}
}