// �ṹ����ϰ�����һ��Ӣ�۵Ľṹ�壬������Ա���������䡢�Ա�
//�����ṹ�����飬�����д��5��Ӣ�ۣ�ͨ��ð��������㷨����������
//Ӣ�۰���������������������մ�ӡ�����Ľ��

#include "test.h"

using namespace std;

struct hero
{
    string name;
    int old;
    string sex;
};

int main()
{
    struct hero Array[5];
    int len = sizeof(Array) / sizeof(Array[0]);
    //1. ��ʼ���ṹ��
    Initiate(Array, len);
    //2.��ӡ
    PrintfStruct(Array, len);
    //3. ð������
    SortStruct(Array, len);
    //4. ��ӡ
    PrintfStruct(Array, len);
    system("pause");
    return 0;
}

void Initiate(struct hero *Array, int len)
{
    Array[0] = {"����", 23, "��"};
    (*(Array + 1)) = {"����", 22, "��"};
    (*(Array + 2)) = {"�ŷ�", 20, "��"};
    (*(Array + 3)) = {"����", 21, "��"};
    (*(Array + 4)) = {"����", 19, "Ů"};
}

void PrintfStruct(struct hero *Array, int len)
{
    for(int i = 0;i < len;i++)
    {
        cout << (Array + i)->name << ' ' << 
        (Array + i)->old << ' ' << (Array + i)->sex << endl;
    }
}

void SortStruct(struct hero *Array, int len)
{
    struct hero temp;
    for(int i = 0;i < len - 1;i++)
    {
        for(int j = 0;j < len - i - 1;j++)
        {
            if((Array + j)->old > (Array + j + 1)->old)
            {
                temp = *(Array + j);
                *(Array + j) = *(Array + j + 1);
                *(Array + j + 1) = temp;
            }
        }
    }
}