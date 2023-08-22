#include "Grid.hpp"
#include <iostream>

using namespace std;

int mainMain()
{
	Grid<int> myIntGrid;
	Grid<double> myDoubleGrid{ 11, 11 };
	
	myIntGrid.at(0, 0) = 10;
	int x{ myIntGrid.at(0,0).value_or(0) };
	
	Grid<int> grid2{ myIntGrid };
	Grid<int> anotherIntGrid;
	anotherIntGrid = grid2;

	// Grid ���ø� Ŭ������ �پ��� Ȱ��
	Grid<const char*> myStringGrid;
	myStringGrid.at(2, 2) = "Hello";
	Grid<vector<int>> gridOfVectors;
	vector<int> myVector{ 1,2,3,4 };
	gridOfVectors.at(5, 6) = myVector;

	// �ν��Ͻ�ȭ�� ���� ��ü�� �������� �������� ����
	auto myGridOnHeap{ make_unique<Grid<int>>(2, 2) };
	myGridOnHeap->at(0, 0) = 10;
	int x2{ myGridOnHeap->at(0, 0).value_or(0) };
	
	return 0;
}