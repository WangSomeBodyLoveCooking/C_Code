#include <iostream>
using namespace std;

//3. �����������������൱�ڵ�ַ���ݣ�
void func(int &b)
{
    b++;
    return;
}

//4.��������������ֵ��1.��Ҫ���ؾֲ����������ã�2.������������ֵ��
int& fun()
{
    int a = 0;
    return a;
}

int main()
{
    //1.���õĶ���
    int a = 0;
    int &b = a; //���ñ����ʼ��,�ҳ�ʼ���󲻿ɸı�
    // int &c; //error
    int c = 100;
    b = c;  //���Ǹı����ã����Ǹ�ֵ����
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;  //����100

    func(a);
    cout << a << endl;  //101

    int &e = fun();  //��Ҫ���ؾֲ�����������
    cout << e << endl;  //���ֵ��error

    fun() = 100;  //��������ֵ
    cout << e << endl;  



//5. ���õı���
    int &x = a; // ���������� int *const x = &a;    Ϊһ��ָ�볣��
    x = 20; // ���������� *a = 20;

//6. ����������
    // int &y = 10;    // error ���ñ���ָ��Ϸ����ڴ�ռ䣨ջ���������
    const int &y = 10; //���ǺϷ���
    function(10);   //���ǺϷ���
    system("pause");
    return 0;
}

void function(const int &a) //�� ��������
{

}