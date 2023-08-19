#include "Spreadsheet.hpp"
#include "StringSpreadsheetCell.hpp";
#include "DoubleSpreadsheetCell.hpp";
#include "SpreadsheetCell2.hpp"
using namespace std;

int main()
{
	vector<unique_ptr<SpreadsheetCell2>> cellArray;
	
	cellArray.push_back(make_unique<StringSpreadsheetCell>());
	cellArray.push_back(make_unique<StringSpreadsheetCell>());
	cellArray.push_back(make_unique<DoubleSpreadsheetCell>());
	
	cellArray[0]->set("Hello");
	cellArray[1]->set("10");
	cellArray[2]->set("18");
	cout << format("Vector: [{}, {}, {}]", cellArray[0]->getString(),
		cellArray[1]->getString(),
		cellArray[2]->getString()) << endl;

	return 0;
}