#include <iostream>

using namespace std;

class Phone
{
public:
    Phone(string name) : p_name(name)
    {
        cout << "Phone���캯��" << endl;
    }

    ~Phone()
    {
        cout << "Phone��������" << endl;
    }

private:
    string p_name;
};

Phone phone = Phone("IPX");

class Person
{
public:
    Person(string name, string p_name) : m_name(name), m_phone(p_name)      // m_phone(p_name) �൱�� Phone m_phone = p_name  ��ʽת������ʼ������
    {
        cout << "Person���캯��" << endl;
    }
    
    // Person(string name, Phone phone) : m_name(name), m_phone(phone)      // ������Ķ���
    // {
    //     cout << "Person���캯��" << endl;
    // }

    ~Person()
    {
        cout << "Person��������" << endl;
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