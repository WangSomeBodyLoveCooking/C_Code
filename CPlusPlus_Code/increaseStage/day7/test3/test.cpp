#include <iostream>

using namespace std;
class Building;
class Person
{
    public:
        Person();
        void visit();
    public:
        Building *building;
};

class Building
{
    friend void Person::visit();    //成员函数做友元
    public:
        Building();
        string sittingRoom;
    private:
        string bedRoom;
};

Building::Building()
{
    this->bedRoom = "卧室";
    this->sittingRoom = "客厅";
}

Person::Person()
{
    this->building = new Building;
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