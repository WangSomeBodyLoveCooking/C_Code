//��Ԫ
//1.ȫ�ֺ�������Ԫ
//2.������Ԫ
//3.���еĳ�Ա��������Ԫ
#include <iostream>
#include <string>
using namespace std;

class Building
{
    friend void visit(Building room);
    friend class Person;
    
    public:
        Building()
        {}

        Building(string duliRoom, string bedRoom)
        {
            this->bedRoom = bedRoom;
            this->duliRoom = duliRoom;
        }
    public:
        string duliRoom;
    private:
        string bedRoom;
};

class Person
{
public:
    Person()
    {
        building = new Building("keting", "woshi");
    }

    void visit1()
    {
        cout << building->duliRoom << endl;
        cout << building->bedRoom << endl;
    }
private:
    Building *building;
};

void visit(Building room)
{
    cout << room.duliRoom << endl;
    cout << room.bedRoom << endl;
}

int main()
{
    Building room("����", "����");
    visit(room);
    Person p;
    p.visit1();
    system("pause");
    return 0;
}