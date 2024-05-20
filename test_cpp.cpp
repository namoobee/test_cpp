﻿#include <iostream>
#include <string>

using namespace std;

class Snack
{
public:
	int Price; // 가격
	string Name; // 상품이름
	string Company; // 제조회사

	Snack() : Price(0), Name(""), Company("") {}

	Snack(int price, string name, string company)
	{
		this->Price = price;
		this->Name = name;
		this->Company = company;
	}
	virtual void PrintCompany() = 0; 
};


class Candy : public Snack
{
public:
	string Taste; // 맛

	Candy(string taste, int price, string name, string company)
	{
		this->Taste = taste;
		this->Price = price;
		this->Name = name;
		this->Company = company;
	}
	void PrintCompany() override
	{
		cout << "제조사: " << this->Company << endl;
	}
};

class Chocolate : public Snack
{
public:
	string Shape; // 모양

	Chocolate(string shape, int price, string name, string company)
	{
		this->Shape = shape;
		this->Price = price;
		this->Name = name;
		this->Company = company;
	}
	void PrintCompany() override
	{
		cout << "제조사: " << this->Company << endl;
	}
};

int main()
{
	Snack* SnackBasket[4]; 
	SnackBasket[0] = new Candy("salty", 1500, "아이셔", "오리온");
	SnackBasket[1] = new Candy("sweet", 1000, "땅콩캬라멜", "크라운"); 
	SnackBasket[2] = new Chocolate("rectangle", 2100, "가나", "롯데제과"); 
	SnackBasket[3] = new Chocolate("triangle", 2500, "토블론", "몬델리즈"); 

	for (int i = 0; i < 4; i++)
	{
		cout << SnackBasket[i]->Name << ", "; 
		SnackBasket[i]->PrintCompany();
	}
	// 동적 할당된 메모리를 해제
	for (int i = 0; i < 4; i++)
	{
		delete SnackBasket[i];
	}
	return 0;
}
// candy, chocolate의 생성자에서 각각 제조사를 입력 받는다는 것은 main함수의 