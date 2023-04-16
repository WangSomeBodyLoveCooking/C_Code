//类模板与函数模板的区别
//1. 类模板不能使用自动类型推导，只能使用显示指定类型
//2. 类模板的模板参数列表可以使用默认参数；

#include <iostream>
#include <string>
using namespace std;

template <class nameType, class ageType = int>  //类模板可以使用默认参数
class Person
{
    public:
        Person(nameType name, ageType age)
        {
            this->name = name;
            this->age = age;
        }

        void printPerson()
        {
            cout << "name = " << this->name << "\nage = " << this->age << endl;
        }

    private:
        nameType name;
        ageType age;
};

void test()
{
    // Person p("Tom", 20);    //类模板不能使用自动类型转换，只能使用显示指定类型
    Person <string, int> p("Tom", 20);
    p.printPerson();

    Person <string> per("Jerry", 18);
    per.printPerson();
}

int main()
{
    test();
    system("pause");
    return 0;
}