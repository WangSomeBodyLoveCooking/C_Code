// ģ��ľ����ԣ�����ģ���ͨ���Բ������ܵģ�
// ����Ƚ��������Ƿ���ͬ�ĺ�����ʵ�ο��Դ������������ַ��
// Ϊ�����һ���⣬c++Ϊ�ض������ṩ�˾��廯��ģ��

#include <iostream>
#include <string>
using namespace std;

class Person
{
    public:
        Person(string name, int age)
        {
            this->name = name;
            this->age = age;
        }

        int getAge()
        {
            return this->age;
        }

        string getName()
        {
            return this->name;
        }

    private:
        string name;
        int age;
};

template <typename T>
bool compareFunc(T &a, T &b)
{
    if(a == b)
    {
        return true;
    }

    return false;
}

//C++Ϊ�ض������ṩ�˾��廯ģ��
template<> bool compareFunc(Person &a, Person  &b)  //��Ҫָ���ض�����
{
    if(a.getAge() == b.getAge() && a.getName() == b.getName())
    {
        return true;
    }

    return false;
}


void test()
{
    int a = 10;
    int b = 10;
    Person person1("TOM", 20);
    Person person2 = Person("TOM", 20);

    bool c1 = compareFunc(a, b); //����ʵ��
    bool c2 = compareFunc(person1, person2);  //�޷�ʵ��

    cout << c1 << c2 << endl;
}



int main()
{
    test();
    system("pause");
    return 0;
}