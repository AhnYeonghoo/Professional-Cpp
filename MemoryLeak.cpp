#include <iostream>

using namespace std;

namespace Memory {
	class Simple
	{
	public:
		Simple() { m_intPtr = new int{}; }
		~Simple() { delete[] m_intPtr; }
		void setValue(int value) { *m_intPtr = value; }
	private:
		int* m_intPtr;
	};
};

void doSomething(Memory::Simple*& outSimplePtr)
{
	outSimplePtr = new Memory::Simple{}; // ����! ���� ��ü�� �������� �ʾҴ�.
}

int mainMemoryLeak()
{
	Memory::Simple* simplePtr{ new Memory::Simple {} };
	doSomething(simplePtr);
	delete simplePtr; // �ι�° ��ü�� �����ϹǷ� �޸� ���� �߻�

	return 0;
}