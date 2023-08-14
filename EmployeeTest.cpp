#include "Employee.hpp"


using namespace std;
using namespace Records;

int mainEmployeeTest()
{
	cout << "Testing the Employee Class." << endl;
	Employee emp{ "Jane", "Doe" };
	emp.setFirstName("JoHn");
	emp.setLastName("Doe");
	emp.setEmployeeNumber(71);
	emp.setSalary(50'000);
	emp.promote();
	emp.promote(50);
	emp.hire();
	emp.display();
	return 0;
}