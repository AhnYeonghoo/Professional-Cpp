#include "Database.hpp"

using namespace std;
using namespace Records;

int mainDatabaseTest()
{
	Database myDB;
	Employee& emp1{ myDB.addEmployee("Greg", "Wallis") };
	emp1.fire();
	
	Employee& emp2{ myDB.addEmployee("Marc", "White") };
	emp2.setSalary(100'100);
	
	Employee& emp3{ myDB.addEmployee("JoHn", "Doe") };
	emp3.setSalary(10'000);
	emp3.promote();
	
	cout << "All Employees: " << endl << endl;
	myDB.displayAll();
	
	cout << endl << "Current Employees: " << endl << endl;
	myDB.displayCurrent();
	
	cout << endl << "Former employees: " << endl << endl;
	myDB.displayFormer();

	return 0;
}