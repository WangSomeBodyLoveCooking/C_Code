// ��̬��Ա�����;�̬��Ա����

// ���ھ�̬��Ա������
/*
�����ж�����һ�ݾ�̬��Ա����������ͨ������������������ʣ�
���ڱ���׶ξ��Ѿ��������ڴ棻
����Ҫ�����ڶ��壬��������г�ʼ����
�ܾ�̬��Ա����Ҳ����Ȩ�����Ƶģ�
*/

//���ھ�̬��Ա����:
/*
�����ж�����ͬһ��̬��Ա������������ͨ������������������ʣ�
�ھ�̬��Ա����ֻ�ܲ�����̬��Ա����������Ϊ������������ʾ�̬��Ա��������֪�������ĸ�����ķǾ�̬��Ա������
*/

#include <iostream>

using namespace std;

class Person
{

public:
    static int age;
    int weight;

    static void func1()
    {
        age++;
        height++;
    }

private:
    static int height;
};

int Person ::age = 20;
int Person ::height = 170;

void func()
{
    Person p1;
    cout << p1.age << endl; //20
    cout << Person::age << endl;    //20
    p1.func1();
    Person::func1();
    cout << p1.age << endl; //22
    cout << Person::age << endl; //22
}

int main()
{
    func();
    system("pause");
    return 0;
}