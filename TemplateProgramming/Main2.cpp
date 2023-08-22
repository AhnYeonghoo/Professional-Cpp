#include "Grid2.hpp"
#include <iostream>
using namespace std;

int main()
{
	Grid2<int, 10, 10> myGrid;
	Grid2<int, 10, 10> anotherGrid;
	myGrid.at(2, 3) = 42;
	anotherGrid = myGrid;
	cout << anotherGrid.at(2, 3).value_or(0) << endl;
	return 0;
}