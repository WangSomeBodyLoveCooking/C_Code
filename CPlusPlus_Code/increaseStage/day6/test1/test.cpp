#include <iostream>

using namespace std;

class Person
{
    public:
        void showClassName()
        {
            cout << "This is Person class" <<endl;
        }
        void showPerson()
        {
            cout << m_Age << endl;
            // cout << this->m_Age << endl;
        }

        int m_Age;
};

void test1()
{
    Person *p = NULL;
    p->showClassName(); //��ָ�룬���Ե��ú���
    p->showPerson();    //���������Ա�������õ���thisָ�룬�Ͳ����ÿպ���������
}

int main()
{

    test1();
    system("pause");
    return 0;
}