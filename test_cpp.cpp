#include <iostream>
using namespace std;

class Shape
{
protected:
	virtual void draw() = 0;
};

class Circle : public Shape
{
public:
	void draw() override
	{
		cout << "Circle" << endl;
	}
};

class Rectangle : public  Shape
{
public:
	void draw() override
	{
		cout << "Rectangle" << endl;
	}
};

class Triangle : public  Shape
{
public:
	void draw() override
	{
		cout << "Triangle" << endl;
	}
};

int main()
{
	Circle Cir;
	Cir.draw();

	Rectangle Rect;
	Rect.draw();

	Triangle Tri;
	Tri.draw();

	return 0;
}