// 类模板对象作为函数参数
// 三种传入方式：①指定传入类型；②参数模板化；③整个类模板化

#include <iostream>
using namespace std;
#include <string>

//1. 定义个类模板
template <class nameType, class ageType>
class Person
{
    public:
        Person(nameType name, ageType age) : name(name), age(age)
        {

        }

        void showPerson()
        {
            cout << "name = " << this->name << "\nage = " << this->age <<endl;
        }

    private:
        nameType name;
        ageType age;    
};

// 2.1 指定传入类型
void printPerson1(Person<string, int> p)
{
    p.showPerson();
}

// 2.2  参数模板化
template<typename T1, typename T2>
void printPerson2(Person<T1, T2>p)
{
    p.showPerson();
}

// 2.3 整个类模板化
template<typename T>
void printPerson3(T p)
{
    p.showPerson();
}

void test01()
{
    Person<string, int>p("Tom", 100);
    printPerson1(p);

    Person<string, int>p1("To", 100);
    printPerson2(p1);

    Person<string, int>p2("T", 100);
    printPerson2(p2);
}

// 3. 后两种方式属于类模板与函数模板的结合；推荐使用 指定传入类型

int main()
{
    test01();
    system("pause");
    return 0;
}
