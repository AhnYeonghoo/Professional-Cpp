#include <iostream>
#include <vector>

class Shape
{
public:
	virtual void render() = 0;
};

class Square : public Shape
{
public:
	virtual void render() override {}
};

class Circle : public Shape
{
public:
	void render() override {}
};

class Renderer
{
public:
	void render(const std::vector<Shape*>& objects)
	{
		for (auto& object : objects) { object->render(); }
	}
};
