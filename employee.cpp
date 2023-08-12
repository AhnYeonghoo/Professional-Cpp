#include <iostream>
#include <format>
#include "employee.hpp"

using namespace std;

int mainEmployee()
{
	Employee anE;
	anE.firstInitial = 'J';
	anE.lastinitial = 'D';
	anE.employeeNumber = 42;
	anE.salary = 80000;
	cout << format("Employee: {} {}", anE.firstInitial, anE.lastinitial) << endl;
	cout << format("Number: {}", anE.employeeNumber) << endl;
	cout << format("Salary: ${}", anE.salary) << endl;

	return 0;
}