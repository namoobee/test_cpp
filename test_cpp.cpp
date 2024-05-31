#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Snack
{
protected:
    string taste;
    string shape;

public:
    Snack(string t, string s)
        : taste(t), shape(s) {}

    virtual ~Snack() {}

    virtual void Print() const = 0;

    string getTaste() const { return this->taste; }
    string getShape() const { return this->shape; }
};

class Candy : public Snack
{
public:
    Candy(string taste)
        : Snack(taste, "") {}

    void Print() const override
    {
        cout << this->getTaste() << "맛 사탕" << endl;
    }
};

class Chocolate : public Snack
{
public:
    Chocolate(string shape)
        : Snack("", shape) {}

    void Print() const override
    {
        cout << this->getShape()<< "모양 초콜릿" << endl;
    }
};

int main()
{
    vector<Snack*> SnackBasket;
    int choice;

    while (true)
    {
        cout << "과자 바구니에 추가할 간식을 고르시오. (1: 사탕, 2: 초콜릿, 0: 종료) : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string taste;
            cout << "맛을 입력하세요. : ";
            cin >> taste;
            SnackBasket.push_back(new Candy(taste));
            break;
        }
        case 2:
        {
            string shape;
            cout << "모양을 입력하세요: ";
            cin >> shape;
            SnackBasket.push_back(new Chocolate(shape));
            break;
        }
        case 0:
            cout << "과자 바구니에 담긴 간식의 개수는 " << SnackBasket.size() << "개 입니다." << endl;
            cout << "과자 바구니에 담긴 간식 확인하기!" << endl;
            for (auto& snack : SnackBasket)
            {
                snack->Print();
                delete snack;
            }
            SnackBasket.clear();
            return 0;
        default:
            cout << "0 ~ 2 사이의 숫자를 입력하세요." << endl;
        }
    }
    return 0;
}