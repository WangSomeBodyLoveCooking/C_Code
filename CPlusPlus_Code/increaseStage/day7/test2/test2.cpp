#include <iostream>
#include <string>
using namespace std;

class Building
{
    friend class Person;    // ������Ԫ�����Է��ʸ���private����

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

Building::Building() //���ⶨ���Ա����
{
    this->bedRoom = "����";
    this->sittingRoom = "����";
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