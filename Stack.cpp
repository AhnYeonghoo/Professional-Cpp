#include <iostream>
#include <string>

class Stack;
class Node
{
	friend class Stack;
private:
	int val; // ���� ����� ��
	Node* next; // ���� ��带 ����Ű�� ��� ������
	Node(int value = 0, Node* newNode = nullptr)
		: val{value}, next{newNode} {}
};

class Stack
{
private:
	Node* top; // ������ �� �� �κ��� ����Ű�� ������
public:
	explicit Stack() : top {nullptr} {}
	bool isEmpty() const; // ������ ����ִ��� �˻��Ѵ�.
	void pushStack(const int& val); // ���ÿ� ��� ����
	int* popStack(int& val); // ������ �� �� �κ� ����
	void show() const; // ���� ������ ���� 
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