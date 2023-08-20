#include <iostream>

using namespace std;

class Dog
{
public:
	virtual void bark() { cout << "Woof!" << endl; }
	virtual void eat() { cout << "The dog ate" << endl; }
};

class Bird
{
public:
	virtual void chirp() { cout << "Chirp!" << endl; }
	virtual void eat() { cout << "The Bird ate" << endl; }
};

class DogBird : public Dog, public Bird
{
public:
	void eat() override
	{
		Dog::eat(); // ��������� Dog ������ eat()�� ȣ���Ѵ�.
	}
};

int main()
{
	DogBird myConfusedAnimal;
	myConfusedAnimal.bark();
	myConfusedAnimal.chirp();
	return 0;
}