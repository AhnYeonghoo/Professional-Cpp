#include <iostream>
#include "Spreadsheet.hpp"
using namespace std;

int main()
{
	cout << "SpreadsheetProject" << endl;
	SpreadsheetApplication theApp;
	Spreadsheet s1{ theApp };
	Spreadsheet s3{ theApp, 5, 6 };
	Spreadsheet s4{ s3 };
	s1 = s4;

	return 0;
}