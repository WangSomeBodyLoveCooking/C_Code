// �ṹ����ϰ�����һ��Ӣ�۵Ľṹ�壬������Ա���������䡢�Ա�
//�����ṹ�����飬�����д��5��Ӣ�ۣ�ͨ��ð��������㷨����������
//Ӣ�۰���������������������մ�ӡ�����Ľ��
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct Haro
{
    string sex;
    int age;
    string name;
};

void Iniate(Haro *haros, int len)
{
    string name = "Ӣ��";
    char *a = (char *)"ABCDE";
    int age;
    for(int i = 0;i < len;i++)
    {
        (haros + i)->name = name;
        (haros + i)->name += *(a + i);
        while(1)
        {
            age = rand() % 30;
            if(age >= 20)
            {
                break;
            }
        }
        (haros + i)->age = age;
        (haros + i)->sex = "��";
    }
}

void PrintHaros(Haro *haros, int len)
{
    for(int i = 0; i < len;i++)
    {
        cout << "[" << (haros + i)->name << "," << (haros + i)->age << "," << (haros + i)->sex << "]" << endl;
    }
}

void SortHarosUsingAge(Haro *haros, int len)
{
    for(int i = 0;i < len -1;i++)
    {
        for(int j = 0;j < len - i - 1;j++)
        {
            if((haros+j)->age > (haros+j+1)->age)
            {
                struct Haro temp =  *(haros+j);
                *(haros+j) = *(haros+j+1);
                *(haros+j+1) = temp;
            }
        }
    }
}

int main()
{
    srand((unsigned int)time(NULL));
    Haro haros[5];
    int len = sizeof(haros) / sizeof(haros[0]);
    Iniate(haros, len);
    PrintHaros(haros, len);
    SortHarosUsingAge(haros, len);
    PrintHaros(haros, len);
    system("pause");
    return 0;
}