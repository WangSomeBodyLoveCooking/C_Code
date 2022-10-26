#include <iostream>

using namespace std;

class Person
{
    friend Person operator+(Person &p, int height);
    friend ostream &operator<<(ostream &cout, Person &p);

public:
    Person(int age, int height)
    {
        this->age = age;
        this->height = height;
    }

    Person operator+(Person &p) //�Ӻ����������
    {
        Person temp(0, 0); //����д��Person temp��ӦΪ�ṩ���вΣ��������Ͳ����ṩ�޲ι���
        temp.age = this->age + p.age;
        temp.height = this->height + p.height;
        return temp;
    }

    //��Ա���� ʵ�ֲ��� p << cout ����������Ҫ��Ч��
    // void operator<<(Person& p){
    // }

private:
    int age;
    int height;
};

Person operator+(Person &p, int height) //�Ӻ����������,��������
{
    p.height += height;
    return p;
}

//ȫ�ֺ���ʵ�� + �����������
// Person operator+(const Person& p1, const Person& p2) {
// Person temp(0, 0);
// temp.m_A = p1.m_A + p2.m_A;
// temp.m_B = p1.m_B + p2.m_B;
// return temp;
//}


//ȫ�ֺ���ʵ����������
//ostream����ֻ����һ��
ostream &operator<<(ostream &cout, Person &p)
{
    cout << "p.age\t" << p.age << "\tp.height" << p.height;
}

void test()
{
    Person p1(28, 175);
    Person p2(1, 1);
    Person p3 = p1 + p2; // Person p3 = p1.operator+ (p1);
    p3 = p1 + 10;        // Person p3 = operator+ (p1, 10);
    cout << p3 << endl;  // operator<<.(cout, p3);
}

int main()
{
    test();
    system("pause");
    return 0;
}