#include <iostream>
using namespace std;

class Person
{
    public:
        Person(int age)
        {
            this->age = age;
            // age = age;
        }
    
    // void personAddPerson(Person a)
    // {
    //     this->age += a.age;
    // }

    // Person & personAddPerson(Person a)
    // {
    //     this->age += a.age;
    //     return *this;
    // }

     Person personAddPerson(Person a)
    {
        this->age += a.age;
        return *this;
    }

    int age;
};

void test1()
{
    Person p(10);
    cout << "p.age = " <<p.age << endl;
}

void test2()
{
    Person p1(10);
    Person p2(10);
    // p2.personAddPerson(p1);
    p2.personAddPerson(p1).personAddPerson(p1).personAddPerson(p1);
    cout << "p.age = " <<p2.age << endl;    // 20
    cout << "p.age = " <<p2.personAddPerson(p1).personAddPerson(p1).age << endl;    //40
    cout << "p.age = " <<p2.personAddPerson(p1).age << endl;    //40
    cout << "p.age = " <<p2.personAddPerson(p1).personAddPerson(p1).personAddPerson(p1).age << endl;   //70
    





}

int main()
{
    // test1();
    test2();
    system("pause");
    return 0;
}