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
	int i{ 7 }; // 스택에 저장되는 자동 변수
	int* ptr{ nullptr }; // 스택에 ptr 포인터 변수가 저장됨
	ptr = new int; // 프리스토어에 *ptr(ptr 포인터 변수가 가리키는 변수의 값)이 저장됨
	
	int** handle{ nullptr };
	handle = new int*;
	*handle = new int;
	// 위 경우엔 **handle 포인터 변수와 *handle 포인터 변수 모두 프리스토어에 저장된다.
	delete ptr;
	ptr = nullptr;
	delete* handle;
	*handle = nullptr;
	delete handle;
	handle = nullptr;
	// 항상 delete과 nullptr로 초기화 하는 과정을 잊지말자!
	

	int* ptr2{ new int };
	delete ptr2;
	ptr2 = nullptr;
	
	// C++에선 malloc과 free를 절대 사용하지 말고 new와 delete를 사용하도록 한다.
	
	int* ptr3{ new(nothrow) int }; // 예외 발생을 하지 않도록 하기 위해 new의 인수로 nothrow를 보낸다.
	delete ptr3;
	ptr3 = nullptr;
	
	// Arrays
	int myArray[5]; // 스택에 5개의 배열이 생성됨
	myArray[0] = { 1 };
	myArray[1] = { 2 };
	myArray[2] = { 3 };
	myArray[3] = { 4 };
	myArray[4] = { 5 };
	
	int myArray2[5]{ 1,2,3,4,5 };
	int myArray3[5]{ 0 }; // 모든 요소를 0으로 초기화하는 영초기화
	int myArray4[]{ 1,2,3,4,5 }; // 컴파일러가 배열 원소 개수를 자동으로 알아냄
	
	// 배열 포인터
	int* myArrayPtr{ new int[5] }; 
	// 스택에는 myArrayPtr이 저장되고 
	// 프리스토어에는 myArrayPtr이 가리키는 myArrayPtr[0]부터 4까지 저장됨
	int* myArrayPtr2 { new int[5] {1,2,3,4,5} }; // 포인터 배열도 초기화 리스트 사용 가능
	delete[] myArrayPtr;
	myArrayPtr = nullptr;
	delete[] myArrayPtr2;
	myArrayPtr2 = nullptr;
	

	// Caution!! C++에서 realloc() 함수는 절대 사용하지 말자!

	// 객체의 동적할당
	Simple* mySimpleArray{ new Simple[4] }; // 생성자가 총 4번 호출된다.
	// 스택에는 mySimpleArray가 저장되고
	// 프리스토어에는 mySimpleArray[0]부터 3까지 저장된다(실제 객체)
	delete[] mySimpleArray;
	mySimpleArray = nullptr; // 반드시 사용한 메모리는 해제한다.
	
	// 배열의 원소가 객체일 때만 소멸자가 호출된다.
	// 포인터 배열에 대해 delete[]를 호출할 때는 각 원소가 가리키는 객체를 일일이 해제해야 한다.
	
	const size_t size{ 4 };
	Simple** mySimplePtrArray{ new Simple * [size] };
	// 포인터마다 객체를 할당한다.
	for (size_t i{ 0 }; i < size; i++) {
		mySimplePtrArray[i] = new Simple();
	}
	
	// 할당된 객체를 일일이 삭제해주어야 한다.
	for (size_t i{ 0 }; i < size; i++) {
		delete mySimplePtrArray[i];
		mySimplePtrArray[i] = nullptr;
	}

	delete[] mySimplePtrArray;
	mySimplePtrArray = nullptr;

	// 이와 같은 C Style Pointer는 레거시 프로젝트에서 자주 볼 수 있어, 코드를 읽을 때 도움이 되지만,
	// 새로운 코드를 작성할 때는 가급적 C++ Style Pointer를 사용한다.
	// 예를 들어 1차원 배열은 std::vector<T>로, 이차원 배열은 std::vector<std::vector<T>>로 사용하면 편리하다.
	return 0;

	
}

void leaky()
{
	new int; // 메모리 누수 발생
	cout << "방금 int 하나를 잃어버렸다." << endl;
}

// 2차원 배열을 동적으로 할당해주는 함수
char** allocateCharacterBoard(size_t xDimension, size_t yDimension)
{
	char** myArray{ new char* [xDimension] }; // 첫 번째 차원의 배열을 먼저 할당해준다.
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