#include <typeinfo>
#include <iostream>
using namespace std;

class Animal2 { public: virtual ~Animal2() = default; };
class Dog2 : public Animal2 {};
class Bird2 : public Animal2 {};

void speak(const Animal2& animal)
{
	if (typeid(animal) == typeid(Dog2)) {
		cout << "Woof!" << endl;
	}
	else if (typeid(animal) == typeid(Bird2)) {
		cout << "Chirp!" << endl;
	}
}

class Loggable
{
public:
	virtual ~Loggable() = default;
	virtual std::string getLogMessage() const = 0;
};

class Foo : public Loggable
{
public:
	std::string getLogMessage() const override { return "Hello Logger"; }
};

void logObject(const Loggable& loggableObject)
{
	cout << typeid(loggableObject).name() << ": ";
	cout << loggableObject.getLogMessage() << endl;
}