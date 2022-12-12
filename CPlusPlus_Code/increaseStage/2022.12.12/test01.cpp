//��ֵ���������
//C++������Ϊһ�����ṩ�ĸ�����
// ���캯��   ��������   ��������    ��ֵoperator=
#include <iostream>

using namespace std;

class Person
{

    friend void test1();

    public:
        Person(int age)
        {
            m_age = new int(age);
        }

        ~Person()
        {
            if(NULL != m_age)
            {
                delete m_age;
                m_age = NULL;
            }
        }

        Person& operator=(Person &p)//c++����ʱ����������Ϊ��const�����ò�����������벻ͨ����;��˱��뷵�����ã���������
        {
            if(NULL != m_age)
            {
                delete m_age;
                m_age = NULL;
            }

            m_age = new int(*p.m_age);
            return *this;
        }

    private:
        int *m_age;
};

void test1()
{
    Person p1(20);
    Person p2(21);
    Person p3(23);
    p3 = p2 = p1;   //c++����ʱ����������Ϊ��const�����ò���;��˱��뷵�����ã���������

    cout << *p1.m_age << endl;
    cout << *p2.m_age << endl;
    cout << *p3.m_age << endl;
    

}
int main()
{
    test1();
    cout << "ByeBye" << endl;
    system("pause");
    return 0;
}