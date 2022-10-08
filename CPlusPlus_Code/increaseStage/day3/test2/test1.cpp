#include <iostream>

using namespace std;

class Person
{
    public:
        Person(int age, int height)
        {
            m_age = age;
            // int *m_height = new int(height); //大错特错
            m_height = new int(height);
        }

        Person(const Person &p)
        {
           m_age = p.m_age;
           m_height = new int(*p.m_height);
        }

        ~Person()
        {
            if(NULL != m_height)
            {
                delete m_height;
                m_height = NULL;
            }
            cout << "Person析构函数" << endl;
        }

    public:
        int m_age;
        int *m_height;
};

void test()
{
    Person p1(20, 170);
    cout << p1.m_age << endl;
    cout << *p1.m_height << endl;
    Person p2(p1);
    cout << p2.m_age << endl;
    cout << *p2.m_height << endl;
}

int main()
{
    test();
    system("pause");
    return 0;
}