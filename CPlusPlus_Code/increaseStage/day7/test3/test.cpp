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
    friend void Person::visit();    //��Ա��������Ԫ
    public:
        Building();
        string sittingRoom;
    private:
        string bedRoom;
};

Building::Building()
{
    this->bedRoom = "����";
    this->sittingRoom = "����";
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