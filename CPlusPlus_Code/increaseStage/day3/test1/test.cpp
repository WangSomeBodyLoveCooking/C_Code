#include <iostream>

using namespace std;

class Person
{
    public:
        Person()
        {
            cout << "PersonĬ�Ϲ��캯��" << endl;
        }

        Person(int age)
        {   
            cout << "Person�вι��캯��" << endl;
        }

        Person(const Person &p)
        {
            cout << "Person�������캯��" << endl;
        }

        ~Person()
        {
            cout << "Person��������" << endl;
        }

    private:
        int m_age;
};

// ���������������󳡾�
// ����һ���Ѿ����ڵĶ�����������һ������
void test1()
{
    Person p1(10); //�����вι��캯��
    Person p2 = Person(p1); //���ÿ������캯��
}

// ����Ϊ�����βδ���
void dowork1(Person p)
{

}

void test2()
{
    Person p1 = 10; //�����вι��캯��
    dowork1(p1); //���ÿ������캯��
}

// ����Ϊ��������ֵ
Person dowork2()
{
    Person p;   // ����Ĭ�Ϲ��캯��
    cout << (int)&p << endl;
    return p;   
}

void test3()
{
    Person p3 = dowork2();  //���ÿ������캯��
    cout << (int)&p3 << endl;

}

int main()
{

    // test1();
    // test2();
    test3();
    system("pause");
    return 0;
}