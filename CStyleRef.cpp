#include <iostream>

using namespace std;

void separateOddsAndEvens(const int arr[], size_t size, int** odds,
	size_t* numOdds, int** evens, size_t* numEvens)
{
	// ¦���� Ȧ���� ������ ����.
	*numOdds = *numEvens = 0;
	for (size_t i = 0; i < size; i++) {
		if (arr[i] % 2 == 0) {
			++(*numOdds);
		}
		else {
			++(*numEvens);
		}
	}

	// ���� ���� �� �迭�� ũ�⿡ �°� ������ �Ҵ��Ѵ�.
	*odds = new int[*numOdds];
	*evens = new int[*numEvens];
	
	// ���� �迭�� ��� Ȧ���� ¦�� ���Ҹ� ���� ���� �迭�� �����Ѵ�.
	size_t oddsPos = 0, evensPos = 0;
	for (size_t i = 0; i < size; i++) {
		if (arr[i] % 2 == 0) {
			(*odds)[oddsPos++] = arr[i];
		}
		else {
			(*evens)[evensPos++] = arr[i];
		}
	}
}

int mainCStyleRef()
{
	int unSplit[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int* oddNums{ nullptr };
	int* evenNums{ nullptr };
	size_t numOdds{ 0 }, numEvens{ 0 };
	
	separateOddsAndEvens(unSplit, std::size(unSplit), &oddNums, &numOdds, &evenNums, &numEvens);
	
	delete[] oddNums; oddNums = nullptr;
	delete[] evenNums; evenNums = nullptr;

	return 0;
}