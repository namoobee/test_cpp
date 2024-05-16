#include <iostream>
using namespace std;

class Shape
{
public:
	int NumOfSides; // 변의 개수
	int width; // 밑변의 길이

	Shape(int num_of_sides, int w) : NumOfSides(num_of_sides), width(w) {} // 생성자

	void printInfo() // 변의 개수와 밑변의 길이를 출력
	{
		cout << "변의 개수: " << NumOfSides << endl << "밑변의 길이: " << width << endl;
	};
};

class Rectangle : public Shape
{
public:
	int Rect_height; // 세로 길이
	int Rect_area; // 넓이

	Rectangle(int num_of_sides, int w, int h): Shape(num_of_sides, w), Rect_height(h), Rect_area(w * h) {} // 생성자

	void area() // 넓이를 구하고 출력
	{
		cout << "사각형의 넓이: " << Rect_area << endl;
	}

	void printInfo(int w, int h) // 변의 개수와 밑변의 길이를 출력
	{
		cout << "사각형의 넓이는 " << w * h << "입니다." << endl;
	};
};

class Triangle : public Shape
{
	int Tri_height; //높이 길이
	int Tri_area; // 넓이

public:
	Triangle(int num_of_sides, int w, int h) : Shape(num_of_sides, w), Tri_height(h), Tri_area(w* h / 2) {} //생성자

	void area()
	{
		cout << "삼각형의 넓이: " << Tri_area << endl;
	}

	void printInfo(int w, int h) // 변의 개수와 밑변의 길이를 출력
	{
		cout << "삼각형의 넓이는 " << w * h / 2 << "입니다." << endl;
	};
};

int main()
{
	Rectangle rect(4, 4, 3); //변의 개수, 밑변의 길이, 높이
	Triangle tri(3, 4, 3); // 변의 개수, 밑변의 길이, 높이
	// rect.area();
	// tri.area();

	rect.Shape::printInfo();
	rect.printInfo(5, 2);

	tri.Shape::printInfo();
	tri.printInfo(2, 3);
	return 0;
}
