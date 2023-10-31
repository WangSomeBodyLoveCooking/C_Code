// test1 ���Ա�ĺϲ�
// ���Ա�1��1��3��5��7, 9�����Ա�2��2,4,6,8��
// ������ϲ�Ϊ��3��135792468��
// ע��������ʽ
#include <stdio.h>
#include <string.h>

typedef struct
{
    int number;
    DataList next;
}Data, *DataList;

DataList CreatDataList(int *a, int num) // ͷ�巨����
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
    //��ȡdataList2�ĸ���
    int num1 = getListNum(dataList1);
    int num2 = getListNum(dataList2);
    Data *p = dataList2->next;
    for (int i = 0; i < num2 && p; i++)
    {
        //�ж�2�е�Ԫ����1���Ƿ����
        if (isExiest(dataList1, p->number))
        {
            continue; // ������������
        }
        // ���������򽫸�ֵ�����1��
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