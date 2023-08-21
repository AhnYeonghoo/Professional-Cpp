#include <iostream>

using namespace std;

class Animal3
{
public:
	virtual void eat() = 0;
	virtual void sleep() { cout << "zzzz..." << endl; }
};

class Dog3 : public virtual Animal3
{
public:
	virtual void bark() { cout << "Woof!" << endl; }
	void eat() override { cout << "The dog ate" << endl; }
};

class Bird3 : public virtual Animal3
{
public:
	virtual void chirp() { cout << "Chirp" << endl; }
	void eat() override { cout << "The bird ate" << endl; }
};

class DogBird3 : public Dog3, public Bird3
{
public:
	virtual void eat() override { Dog3::eat(); }
};

int mainVirtualBaseClass()
{
	DogBird3 myConfusedAnimal;
	myConfusedAnimal.sleep();
	return 0;
}