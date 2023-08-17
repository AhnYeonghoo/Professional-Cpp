#include "SpreadsheetCell.hpp"

using namespace std;

int main()
{
	SpreadsheetCell myCell(5), anotherCell(4);
	cout << myCell.getValue() << endl;
	cout << anotherCell.getValue() << endl;
	myCell.setValue(6);
	anotherCell.setString("3.2");
	cout << myCell.getValue() << endl;
	cout << anotherCell.getValue() << endl;
	cout << endl << endl;

	SpreadsheetCell* myCellp{ new SpreadsheetCell(5) };
	myCellp->setValue(3.7);
	cout << "Cell 1: " << myCellp->getValue() <<
		" " << myCellp->getString() << endl;
	delete myCellp;
	myCellp = nullptr;

	// SmartPointer use.
	auto myCellp2{ make_unique<SpreadsheetCell>(5) };
	(*myCellp2).setValue(3.8);
	cout << "Cell 1: " << myCellp2->getValue() << " " <<
		myCellp2->getString() << endl;

	cout << endl << endl << endl;
	
	auto smartCellp{ make_unique<SpreadsheetCell>(4) };
	// 일반 포인터도 가능하지만, 권장되지 않는다.
	SpreadsheetCell* myCellp3{ new SpreadsheetCell {5} };
	SpreadsheetCell* anotherCellp{ nullptr };
	anotherCellp = new SpreadsheetCell{ 4 };
	delete myCellp3;
	delete anotherCellp;
	myCellp3 = nullptr;
	anotherCellp = nullptr;
	cout << endl << endl << endl;

	SpreadsheetCell aThirdCell{ "Test" };
	SpreadsheetCell aFourthCell{ 4.4 };
	auto aFifthCellp{ make_unique<SpreadsheetCell>("5.5") };
	cout << "aThirdCell: " << aThirdCell.getValue() << endl;
	cout << "aFourthCell: " << aFourthCell.getValue() << endl;
	cout << "aFifthCellp: " << aFifthCellp->getValue() << endl;

	cout << endl << endl;
	
	auto smartCellp2{ make_unique<SpreadsheetCell>() }; // default constructor
	SpreadsheetCell* myCell4{ new SpreadsheetCell{} };
	delete myCell4;
	myCell4 = nullptr;


	return 0;
}