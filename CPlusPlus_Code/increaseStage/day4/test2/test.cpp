#include <iostream>

using namespace std;

class Phone
{
public:
    Phone(string name) : p_name(name)
    {
        cout << "Phone构造函数" << endl;
    }

    ~Phone()
    {
        cout << "Phone析构函数" << endl;
    }

private:
    string p_name;
};

Phone phone = Phone("IPX");

class Person
{
public:
    Person(string name, string p_name) : m_name(name), m_phone(p_name)      // m_phone(p_name) 相当于 Phone m_phone = p_name  隐式转换法初始化对象
    {
        cout << "Person构造函数" << endl;
    }
    
    // Person(string name, Phone phone) : m_name(name), m_phone(phone)      // 传入类的对象
    // {
    //     cout << "Person构造函数" << endl;
    // }

    ~Person()
    {
        cout << "Person析构函数" << endl;
    }

private:
    string m_name;
    Phone m_phone;
};
void func()
{
    Person p("WZX", "Iphone");
    // Person p("WZX", phone);

}
int main()
{
    func();
    system("pause");
    return 0;
}