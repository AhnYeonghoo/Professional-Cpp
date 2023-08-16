#include <iostream>
#include <string>

class Stack;
class Node
{
	friend class Stack;
private:
	int val; // 현재 노드의 값
	Node* next; // 다음 노드를 가르키는 노드 포인터
	Node(int value = 0, Node* newNode = nullptr)
		: val{value}, next{newNode} {}
};

class Stack
{
private:
	Node* top; // 스택의 맨 윗 부분을 가리키는 포인터
public:
	explicit Stack() : top {nullptr} {}
	bool isEmpty() const; // 스택이 비어있는지 검사한다.
	void pushStack(const int& val); // 스택에 요소 삽입
	int* popStack(int& val); // 스택의 맨 윗 부분 추출
	void show() const; // 현재 스택의 상태 
};

bool Stack::isEmpty() const
{
	return top == nullptr;
}

void Stack::pushStack(const int& val)
{
	top = new Node(val, top);
}

int* Stack::popStack(int& val)
{
	if (isEmpty()) {
		std::cout << "Empty Stack" << std::endl;
		return 0;
	}

	Node* x = top;
	val = top->val;
	top = x->next;
	delete x;
	return &val;
}

void Stack::show() const
{
	Node* temp = top;
	while (temp != nullptr) {
		std::cout << temp->val << std::endl;
		temp = temp->next;
	}
}

int mainStack()
{
	Stack st;
	st.pushStack(1);
	st.pushStack(2);
	st.pushStack(3);
	st.show();
	int a = 3;
	const int* b = st.popStack(a);
	st.show();
	std::cout << *b << std::endl;

	
	return 0;
}