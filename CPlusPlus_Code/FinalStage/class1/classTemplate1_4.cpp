// ��ģ�������Ϊ��������
// ���ִ��뷽ʽ����ָ���������ͣ��ڲ���ģ�廯����������ģ�廯

#include <iostream>
using namespace std;
#include <string>

//1. �������ģ��
template <class nameType, class ageType>
class Person
{
    public:
        Person(nameType name, ageType age) : name(name), age(age)
        {

        }

        void showPerson()
        {
            cout << "name = " << this->name << "\nage = " << this->age <<endl;
        }

    private:
        nameType name;
        ageType age;    
};

// 2.1 ָ����������
void printPerson1(Person<string, int> p)
{
    p.showPerson();
}

// 2.2  ����ģ�廯
template<typename T1, typename T2>
void printPerson2(Person<T1, T2>p)
{
    p.showPerson();
}

// 2.3 ������ģ�廯
template<typename T>
void printPerson3(T p)
{
    p.showPerson();
}

void test01()
{
    Person<string, int>p("Tom", 100);
    printPerson1(p);

    Person<string, int>p1("To", 100);
    printPerson2(p1);

    Person<string, int>p2("T", 100);
    printPerson2(p2);
}

// 3. �����ַ�ʽ������ģ���뺯��ģ��Ľ�ϣ��Ƽ�ʹ�� ָ����������

int main()
{
    test01();
    system("pause");
    return 0;
}
