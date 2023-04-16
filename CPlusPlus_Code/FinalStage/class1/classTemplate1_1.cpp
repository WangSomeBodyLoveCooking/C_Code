//类模板的语法
//语法:
// template <class T>
// 类的定义


#include <iostream>
using namespace std;

template <class nameType, class ageType>
class Person
{
    public:
        Person(nameType name, ageType age) : name(name), age(age)
        {

        }

        void printPerson()
        {
            cout << "name :" << this->name << "\tage : " << this->age << endl;
        }

    private:
        nameType name;
        ageType age;
};

void test()
{
    Person <string, int> p("Tom", 20);
    p.printPerson();
}

int main()
{
    test();
    system("pause");
    return 0;
}