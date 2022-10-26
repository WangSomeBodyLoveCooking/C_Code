#include <iostream>

using namespace std;

class Person
{
    friend Person operator+(Person &p, int height);
    friend ostream &operator<<(ostream &cout, Person &p);

public:
    Person(int age, int height)
    {
        this->age = age;
        this->height = height;
    }

    Person operator+(Person &p) //加号运算符重载
    {
        Person temp(0, 0); //不能写成Person temp；应为提供了有参，编译器就不会提供无参构造
        temp.age = this->age + p.age;
        temp.height = this->height + p.height;
        return temp;
    }

    //成员函数 实现不了 p << cout 不是我们想要的效果
    // void operator<<(Person& p){
    // }

private:
    int age;
    int height;
};

Person operator+(Person &p, int height) //加号运算符重载,函数重载
{
    p.height += height;
    return p;
}

//全局函数实现 + 号运算符重载
// Person operator+(const Person& p1, const Person& p2) {
// Person temp(0, 0);
// temp.m_A = p1.m_A + p2.m_A;
// temp.m_B = p1.m_B + p2.m_B;
// return temp;
//}


//全局函数实现左移重载
//ostream对象只能有一个
ostream &operator<<(ostream &cout, Person &p)
{
    cout << "p.age\t" << p.age << "\tp.height" << p.height;
}

void test()
{
    Person p1(28, 175);
    Person p2(1, 1);
    Person p3 = p1 + p2; // Person p3 = p1.operator+ (p1);
    p3 = p1 + 10;        // Person p3 = operator+ (p1, 10);
    cout << p3 << endl;  // operator<<.(cout, p3);
}

int main()
{
    test();
    system("pause");
    return 0;
}