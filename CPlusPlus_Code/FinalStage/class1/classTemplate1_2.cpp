//��ģ���뺯��ģ�������
//1. ��ģ�岻��ʹ���Զ������Ƶ���ֻ��ʹ����ʾָ������
//2. ��ģ���ģ������б����ʹ��Ĭ�ϲ�����

#include <iostream>
#include <string>
using namespace std;

template <class nameType, class ageType = int>  //��ģ�����ʹ��Ĭ�ϲ���
class Person
{
    public:
        Person(nameType name, ageType age)
        {
            this->name = name;
            this->age = age;
        }

        void printPerson()
        {
            cout << "name = " << this->name << "\nage = " << this->age << endl;
        }

    private:
        nameType name;
        ageType age;
};

void test()
{
    // Person p("Tom", 20);    //��ģ�岻��ʹ���Զ�����ת����ֻ��ʹ����ʾָ������
    Person <string, int> p("Tom", 20);
    p.printPerson();

    Person <string> per("Jerry", 18);
    per.printPerson();
}

int main()
{
    test();
    system("pause");
    return 0;
}