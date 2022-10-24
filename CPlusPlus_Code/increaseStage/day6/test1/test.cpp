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
    p->showClassName(); //空指针，可以调用函数
    p->showPerson();    //但是如果成员函数中用到了this指针，就不能用空函数来调用
}

int main()
{

    test1();
    system("pause");
    return 0;
}