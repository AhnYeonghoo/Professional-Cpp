#include <iostream>
#include <array>

using namespace std;

void doubleInts(int* theArray, size_t size);
void doubleInts(int theArray[], size_t size);

template<size_t N>
void doubleIntsStack(int(&theArray)[N]);

int main()
{
	int myIntArray[10]{};
	int* myIntPtr{ myIntArray }; 
	myIntPtr[4] = 5; // �����ͷ� �迭 �ٷ��
	
	for (auto& a : myIntArray) {
		cout << a << " ";
	}

	cout << endl;

	size_t arrSize{ 4 };
	int* freeStoreArray{ new int[arrSize] {1, 5, 3, 4} };
	doubleInts(freeStoreArray, arrSize);
	for (size_t i{ 0 }; i < arrSize; i++) {
		cout << freeStoreArray[i] << " ";
	}
	delete[] freeStoreArray;
	freeStoreArray = nullptr;
	
	cout << endl;

	int stackArray[]{ 5, 7, 9, 11 };
	arrSize = std::size(stackArray);
	doubleInts(stackArray, arrSize);
	// Ȥ��
	doubleInts(&stackArray[0], arrSize);
	for (const auto& arr : stackArray) {
		cout << arr << " ";
	}




	return 0;
}

void doubleInts(int* theArray, size_t size)
{
	for (size_t i{ 0 }; i < size; i++) { theArray[i] *= 2; }
}

// call-by-reference ȿ���� ���� ���� �迭�� ���� �ǵ��.
void doubleInts(int theArray[], size_t size)
{
	for (size_t i{ 0 }; i < size; i++) {
		theArray[i] *= 2;
	}
}

template<size_t N>
void doubleIntsStack(int(&theArray)[N])
{
	for (size_t i{ 0 }; i < N; i++) { theArray[i] *= 2; }
}