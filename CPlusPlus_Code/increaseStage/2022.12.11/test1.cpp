#include <iostream>

using namespace std;
//������������غ͵����ݼ����������

class Person
{
    friend ostream& operator<<(ostream &cout, Person p);
friend Person& operator--(Person& p);
friend Person operator--(Person& p, int);

    public:
        Person(int age) : m_age(age)
        {
            
        }

        Person& operator++()    //�������ã���ͬһ������в�����
        {
            this->m_age++;
            return *this;
        }

        // Person& operator--()    //�������ã���ͬһ������в�����
        // {
        //     this->m_age--;
        //     return *this;
        // }

        Person operator++(int)  //����ֵ�����������ã���Ϊ�ֲ����������ã����Ϸ�
        {
            Person tem(this->m_age);
            this->m_age++;
            return tem;
        }

        //   Person operator--(int)  //����ֵ�����������ã���Ϊ�ֲ����������ã����Ϸ�
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

//������������أ�����ʹ�ó�Ա������ֻ��ʹ��ȫ�ֺ���
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

// void test01()   //�����������������
// {
//     Person p(27);
//     cout << p << endl;
// }

void test02()   //���Ե������������
{
    Person p(27);
    cout << ++p << endl;
    // cout << ++++p << endl; 
    //��ǰ��++����ֵPerson p�����൱���´�����һ��m_ageֵΪpֵ��ͬ�Ķ��󣬵���
    //�´���++ʱ,p��ֵ�Ͳ���仯�ˣ�
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