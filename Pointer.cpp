#include <iostream>

using namespace std;

void leaky();
char** allocateCharacterBoard(size_t xDimension, size_t yDimension);
void releaseCharacterBoard(char**& myArray, size_t xDimension);

class Simple
{
public:
	Simple() { cout << "Simple Constructor Called!" << endl; }
	~Simple() { cout << "Simple Destructor Called!" << endl; }
};

int mainPointer()
{
	int i{ 7 }; // ���ÿ� ����Ǵ� �ڵ� ����
	int* ptr{ nullptr }; // ���ÿ� ptr ������ ������ �����
	ptr = new int; // �������� *ptr(ptr ������ ������ ����Ű�� ������ ��)�� �����
	
	int** handle{ nullptr };
	handle = new int*;
	*handle = new int;
	// �� ��쿣 **handle ������ ������ *handle ������ ���� ��� �������� ����ȴ�.
	delete ptr;
	ptr = nullptr;
	delete* handle;
	*handle = nullptr;
	delete handle;
	handle = nullptr;
	// �׻� delete�� nullptr�� �ʱ�ȭ �ϴ� ������ ��������!
	

	int* ptr2{ new int };
	delete ptr2;
	ptr2 = nullptr;
	
	// C++���� malloc�� free�� ���� ������� ���� new�� delete�� ����ϵ��� �Ѵ�.
	
	int* ptr3{ new(nothrow) int }; // ���� �߻��� ���� �ʵ��� �ϱ� ���� new�� �μ��� nothrow�� ������.
	delete ptr3;
	ptr3 = nullptr;
	
	// Arrays
	int myArray[5]; // ���ÿ� 5���� �迭�� ������
	myArray[0] = { 1 };
	myArray[1] = { 2 };
	myArray[2] = { 3 };
	myArray[3] = { 4 };
	myArray[4] = { 5 };
	
	int myArray2[5]{ 1,2,3,4,5 };
	int myArray3[5]{ 0 }; // ��� ��Ҹ� 0���� �ʱ�ȭ�ϴ� ���ʱ�ȭ
	int myArray4[]{ 1,2,3,4,5 }; // �����Ϸ��� �迭 ���� ������ �ڵ����� �˾Ƴ�
	
	// �迭 ������
	int* myArrayPtr{ new int[5] }; 
	// ���ÿ��� myArrayPtr�� ����ǰ� 
	// ���������� myArrayPtr�� ����Ű�� myArrayPtr[0]���� 4���� �����
	int* myArrayPtr2 { new int[5] {1,2,3,4,5} }; // ������ �迭�� �ʱ�ȭ ����Ʈ ��� ����
	delete[] myArrayPtr;
	myArrayPtr = nullptr;
	delete[] myArrayPtr2;
	myArrayPtr2 = nullptr;
	

	// Caution!! C++���� realloc() �Լ��� ���� ������� ����!

	// ��ü�� �����Ҵ�
	Simple* mySimpleArray{ new Simple[4] }; // �����ڰ� �� 4�� ȣ��ȴ�.
	// ���ÿ��� mySimpleArray�� ����ǰ�
	// ���������� mySimpleArray[0]���� 3���� ����ȴ�(���� ��ü)
	delete[] mySimpleArray;
	mySimpleArray = nullptr; // �ݵ�� ����� �޸𸮴� �����Ѵ�.
	
	// �迭�� ���Ұ� ��ü�� ���� �Ҹ��ڰ� ȣ��ȴ�.
	// ������ �迭�� ���� delete[]�� ȣ���� ���� �� ���Ұ� ����Ű�� ��ü�� ������ �����ؾ� �Ѵ�.
	
	const size_t size{ 4 };
	Simple** mySimplePtrArray{ new Simple * [size] };
	// �����͸��� ��ü�� �Ҵ��Ѵ�.
	for (size_t i{ 0 }; i < size; i++) {
		mySimplePtrArray[i] = new Simple();
	}
	
	// �Ҵ�� ��ü�� ������ �������־�� �Ѵ�.
	for (size_t i{ 0 }; i < size; i++) {
		delete mySimplePtrArray[i];
		mySimplePtrArray[i] = nullptr;
	}

	delete[] mySimplePtrArray;
	mySimplePtrArray = nullptr;

	// �̿� ���� C Style Pointer�� ���Ž� ������Ʈ���� ���� �� �� �־�, �ڵ带 ���� �� ������ ������,
	// ���ο� �ڵ带 �ۼ��� ���� ������ C++ Style Pointer�� ����Ѵ�.
	// ���� ��� 1���� �迭�� std::vector<T>��, ������ �迭�� std::vector<std::vector<T>>�� ����ϸ� ���ϴ�.
	return 0;

	
}

void leaky()
{
	new int; // �޸� ���� �߻�
	cout << "��� int �ϳ��� �Ҿ���ȴ�." << endl;
}

// 2���� �迭�� �������� �Ҵ����ִ� �Լ�
char** allocateCharacterBoard(size_t xDimension, size_t yDimension)
{
	char** myArray{ new char* [xDimension] }; // ù ��° ������ �迭�� ���� �Ҵ����ش�.
	for (size_t i{ 0 }; i < xDimension; i++) {
		myArray[i] = new char[yDimension];
	}
	return myArray;
}

void releaseCharacterBoard(char**& myArray, size_t xDimension)
{
	for (size_t i{ 0 }; i < xDimension; i++) {
		delete[] myArray[i];
		myArray[i] = nullptr;
	}
	delete[] myArray;
	myArray = nullptr;
}