//赋值运算符重载
//C++编译器为一个类提供四个函数
// 构造函数   析构函数   拷贝构造    赋值operator=
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

        Person& operator=(Person &p)//c++中临时变量不能作为非const的引用参数（否则编译不通过）;因此必须返回引用，即对象本身
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
    p3 = p2 = p1;   //c++中临时变量不能作为非const的引用参数;因此必须返回引用，即对象本身

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