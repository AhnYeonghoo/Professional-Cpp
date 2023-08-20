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
		Dog::eat(); // 명시적으로 Dog 버전의 eat()를 호출한다.
	}
};

class BaseStatic
{
public:
	static void beStatic() { cout << "BaseStatic being static." << endl; }
};

class DerivedStatic : public BaseStatic
{
public:
	static void beStatic() { cout << "DerivedStatic keepin it static." << endl; }
};

class Base2
{
public:
	virtual ~Base2() = default;
	virtual void overload() { cout << "Base`s overload()" << endl; }
	virtual void overload(int i) { cout << "Base`s overload(int i)" << endl; }
};

class Derived2 : public Base2
{
public:
	using Base2::overload;
	virtual void overload() override
	{
		cout << "Derived`s overload()" << endl;
	}
};

int mainDogBird()
{
	DogBird myConfusedAnimal;
	myConfusedAnimal.bark();
	myConfusedAnimal.chirp();
	
	BaseStatic::beStatic();
	DerivedStatic::beStatic();
	return 0;
}