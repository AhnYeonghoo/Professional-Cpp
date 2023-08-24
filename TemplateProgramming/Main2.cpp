#include "Grid2.hpp"
#include <iostream>
using namespace std;

int mainMain2()
{
	Grid2<int, 10, 10> myGrid;
	Grid2<int, 10, 10> anotherGrid;
	myGrid.at(2, 3) = 42;
	anotherGrid = myGrid;
	cout << anotherGrid.at(2, 3).value_or(0) << endl;

	// ����� ���ø� �Ű�����ȭ �߱� ������ ����� ���ø� ���
	const size_t height{ 10 };
	Grid2<int, 10, height> testGrid;
	
	return 0;
}