// 结构体练习：设计一个英雄的结构体，包括成员姓名，年龄、性别，
//创建结构体数组，数组中存放5名英雄，通过冒泡排序的算法，将数组中
//英雄按照年龄进行升序排序，最终打印排序后的结果
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
    string name = "英锟斤拷";
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
        (haros + i)->sex = "男";
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