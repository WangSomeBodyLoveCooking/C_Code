// 结构体练习：设计一个英雄的结构体，包括成员姓名，年龄、性别，
//创建结构体数组，数组中存放5名英雄，通过冒泡排序的算法，将数组中
//英雄按照年龄进行升序排序，最终打印排序后的结果

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
    //1. 初始化结构体
    Initiate(Array, len);
    //2.打印
    PrintfStruct(Array, len);
    //3. 冒泡排序
    SortStruct(Array, len);
    //4. 打印
    PrintfStruct(Array, len);
    system("pause");
    return 0;
}

void Initiate(struct hero *Array, int len)
{
    Array[0] = {"刘备", 23, "男"};
    (*(Array + 1)) = {"关羽", 22, "男"};
    (*(Array + 2)) = {"张飞", 20, "男"};
    (*(Array + 3)) = {"赵云", 21, "男"};
    (*(Array + 4)) = {"貂蝉", 19, "女"};
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