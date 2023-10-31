// test1 线性表的合并
// 线性表1（1，3，5，7, 9）线性表2（2,4,6,8）
// 将两表合并为表3（135792468）
// 注：用链表方式
#include <stdio.h>
#include <string.h>

typedef struct
{
    int number;
    DataList next;
}Data, *DataList;

DataList CreatDataList(int *a, int num) // 头插法创建
{
    DataList data = (DataList)malloc(sizeof(Data));
    data->next = NULL;
    Data *temData = data;

    for (size_t i = 0; i < num; i++)
    {
        Data* p = (DataList)malloc(sizeof(Data));
        temData->next = p;
        p->number = a[i];
        p->next = NULL;
        temData = p;
    }

    return data;
}

int getListNum(Data *dataList)
{
    Data * p = dataList->next;
    int cout = 0;

    while (p)
    {
        cout++;
        p = p->next;
    }

    return cout;
}

typedef int bool;
#define TRUE 1
#define FALSE 0

bool isExiest(Data *dataList1, int aimNum)
{
    int num = getListNum(dataList1);

    Data *p = dataList1->next;
    int i = 0;
    for(; i < num && p; i++)
    {
        if (p->number != aimNum)
        {
            continue;
        }

    }

    if (i >= num)
    {
        return FALSE;
    }

    return TRUE;
}

void inserListForNum(Data *dataList1, int aimNum)
{
    int num = getListNum(dataList1);
    Data *p = dataList1->next;
    while (p)
    {
        p = p->next;
    }

    Data *newData = (Data *)malloc(sizeof(Data));
    newData->number = aimNum;
    newData->next = NULL;
    p->next = newData;
}

DataList MergeList(Data *dataList1, Data *dataList2)
{
    //获取dataList2的个数
    int num1 = getListNum(dataList1);
    int num2 = getListNum(dataList2);
    Data *p = dataList2->next;
    for (int i = 0; i < num2 && p; i++)
    {
        //判断2中的元素在1中是否存在
        if (isExiest(dataList1, p->number))
        {
            continue; // 若存在则跳过
        }
        // 若不存在则将该值插入表1中
        inserListForNum(dataList1, p->number);
        p = p->next;
    }
}

void printList(Data *dataList1)
{
    Data *p = dataList1->next;

    while (p)
    {
        printf("\n%u\n", p->number);
    }
}

int main()
{
    int a[] = {1, 3, 5, 7, 9};
    int b[] = {2, 4, 6, 8};
    Data* dataList1 = CreatDataList(a, sizeof(a) / sizeof(a[0]));
    Data* dataList2 = CreatDataList(b, sizeof(b) / sizeof(b[0]));

    MergeList(dataList1, dataList2);

    printList(dataList1);

    return 0;
}