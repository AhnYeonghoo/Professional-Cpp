#include "Grid5.hpp"

int mainFunctionTemplateMain()
{
	// �Լ� ���ø� ����
	int myInt{ 3 }, intArray[]{ 1,2,3,4 };
	const size_t sizeIntArray{ std::size(intArray) };

	size_t res;
	res = Find(myInt, intArray, sizeIntArray); // �߷��ؼ� Find<int>�� ȣ���Ѵ�.
	res = Find<int>(myInt, intArray, sizeIntArray); // ��������� FInd<int>�� ȣ���Ѵ�.


	if (res != NOT_FOUND) {
		std::cout << res << std::endl;
	}

	return 0;
}