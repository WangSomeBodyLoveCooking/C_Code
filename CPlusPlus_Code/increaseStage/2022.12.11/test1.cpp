#include <iostream>

using namespace std;
//左移运算符重载和递增递减运算符重载

class Person
{
    friend ostream& operator<<(ostream &cout, Person p);
friend Person& operator--(Person& p);
friend Person operator--(Person& p, int);

    public:
        Person(int age) : m_age(age)
        {
            
        }

        Person& operator++()    //返回引用，对同一对象进行操作；
        {
            this->m_age++;
            return *this;
        }

        // Person& operator--()    //返回引用，对同一对象进行操作；
        // {
        //     this->m_age--;
        //     return *this;
        // }

        Person operator++(int)  //返回值；若返回引用，则为局部变量的引用，不合法
        {
            Person tem(this->m_age);
            this->m_age++;
            return tem;
        }

        //   Person operator--(int)  //返回值；若返回引用，则为局部变量的引用，不合法
        // {
        //     Person tem(this->m_age);
        //     this->m_age--;
        //     return tem;
        // }

        // int getAge()
        // {
        //     return this->m_age;
        // }
    private:
        int m_age;
};

//左移运算符重载：不能使用成员函数，只能使用全局函数
ostream& operator<<(ostream &cout, Person p)
{
    cout << p.m_age;
    return cout;
}

Person& operator--(Person& p)
{
    p.m_age--;
    return p;
}

Person operator--(Person& p, int)
{
    Person tem(p.m_age);
    p.m_age--;
    return tem;
}

// void test01()   //测试左移运算符重载
// {
//     Person p(27);
//     cout << p << endl;
// }

void test02()   //测试递增运算符重载
{
    Person p(27);
    cout << ++p << endl;
    // cout << ++++p << endl; 
    //若前置++返回值Person p；则相当于新创建了一个m_age值为p值相同的对象，但是
    //下次再++时,p的值就不会变化了；
    cout << p++ << endl;
    cout << p << endl;

    cout << p-- << endl;
    cout << --p << endl;
    cout << p << endl;
}

int main()
{
    // test01();
    test02();
    system("pause");
    return 0;
}