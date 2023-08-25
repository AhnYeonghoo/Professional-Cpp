#include "Grid5.hpp"

int mainFunctionTemplateMain()
{
	// 함수 템플릿 사용법
	int myInt{ 3 }, intArray[]{ 1,2,3,4 };
	const size_t sizeIntArray{ std::size(intArray) };

	size_t res;
	res = Find(myInt, intArray, sizeIntArray); // 추론해서 Find<int>를 호출한다.
	res = Find<int>(myInt, intArray, sizeIntArray); // 명시적으로 FInd<int>를 호출한다.


	if (res != NOT_FOUND) {
		std::cout << res << std::endl;
	}

	return 0;
}