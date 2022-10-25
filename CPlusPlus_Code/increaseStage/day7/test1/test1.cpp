#include <iostream>

using namespace std;

class Person
{
    friend void func(Person &p);    //类外全局函数做友元，可以访问类内private属性
    public:
        Person()
        {
            this->name = "WANG";
            this->age = 10;
        }
        string name;
    
    private:
        int age;
};

void func(Person &p)
{
    cout << p.name << endl;
    cout << p.age << endl;
}

void test()
{
    Person p;
    func(p);
}

int main()
{

    test();
    system("pause");
    return 0;
}