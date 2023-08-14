#include <iostream>

using namespace std;

void separateOddsAndEvens(const int arr[], size_t size, int** odds,
	size_t* numOdds, int** evens, size_t* numEvens)
{
	// 짝수와 홀수의 개수를 센다.
	*numOdds = *numEvens = 0;
	for (size_t i = 0; i < size; i++) {
		if (arr[i] % 2 == 0) {
			++(*numOdds);
		}
		else {
			++(*numEvens);
		}
	}

	// 새롷 만들 두 배열의 크기에 맞게 공간을 할당한다.
	*odds = new int[*numOdds];
	*evens = new int[*numEvens];
	
	// 원본 배열에 담긴 홀수와 짝수 원소를 새로 만들 배열에 복사한다.
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