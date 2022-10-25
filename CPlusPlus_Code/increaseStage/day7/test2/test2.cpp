#include <iostream>
#include <string>
using namespace std;

class Building
{
    friend class Person;    // 类做友元，可以访问该类private属性

public:
    Building();

public:
    string sittingRoom;

private:
    string bedRoom;
};

class Person
{
public:
    Person()
    {
        this->building = new Building;
    }
    void visit();

private:
    Building *building;
};

Building::Building() //类外定义成员函数
{
    this->bedRoom = "卧室";
    this->sittingRoom = "客厅";
}

void Person::visit()
{
    cout << building->sittingRoom << endl;
    cout << building->bedRoom << endl;
}

void test()
{
    Person p;
    p.visit();
}

int main()
{
    test();
    system("pause");
    return 0;
}