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
	outSimplePtr = new Memory::Simple{}; // 버그! 원본 객체를 삭제하지 않았다.
}

int mainMemoryLeak()
{
	Memory::Simple* simplePtr{ new Memory::Simple {} };
	doSomething(simplePtr);
	delete simplePtr; // 두번째 객체만 삭제하므로 메모리 누수 발생

	return 0;
}