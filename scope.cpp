#include <iostream>
#include <format>

class Demo
{
public:
	int get() { return 5; }
};

int get() { return 10; }

namespace NS
{
	int get() { return 20; }
}

struct CircleStruct
{
	int x, y;
	double radius;
};

class CircleClass
{
public:
	CircleClass(int x, int y, double radius) 
		: m_x {x}, m_y {y}, m_radius {radius} {}
private:
	int m_x, m_y;
	double m_radius;
};

class MyClass
{
public:
	MyClass() : m_array{ 0, 1, 2, 3 } {}
private:
	int m_array[4];
};
int mainScope()
{
	Demo d;
	std::cout << d.get() << std::endl;
	std::cout << NS::get() << std::endl;
	std::cout << ::get() << std::endl;
	std::cout << get() << std::endl;

	CircleStruct myStruct = { 10, 10, 2.5 };
	CircleClass myClass = { 10, 10, 2.5 }; // uniform initialize·Î ÅëÀÏ C++11
	return 0;
}