// test1 ���Ա�ĺϲ�
// ���Ա�1��1��3��5��7, 9�����Ա�2��2,4,6,8��
// ������ϲ�Ϊ��3��135792468��
// ע��������ʽ
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Data
{
    int number;
    struct Data *next;
}Data, *DataList;

DataList CreatDataList_Head(int *a, int num) // ͷ�巨����
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

DataList CreatDataList_Tail(int *a, int num) // ͷ�巨����
{
    DataList data = (DataList)malloc(sizeof(Data));
    data->next = NULL;
    
    for (int i = num - 1; i >= 0; i--)
    {
        Data *p = (Data *)malloc(sizeof(Data));
        p->number = a[i];
        p->next = data->next;
        data->next = p;
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

typedef int BOOL;
#define TRUE 1
#define FALSE 0

BOOL isExiest(Data *dataList1, int aimNum)
{
    int num = getListNum(dataList1);

    Data *p = dataList1->next;
    int i = 0;
    for(; i < num && p; i++)
    {
        if (p->number != aimNum)
        {
            p = p->next;
            continue;
        }

        break;
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
    Data *q = p;

    while (p)
    {
        q = p;
        p = p->next;
    }

    Data *newData = (Data *)malloc(sizeof(Data));
    newData->number = aimNum;
    newData->next = NULL;
    q->next = newData;
}

void inserList(Data *dataList1, int aimNum)
{
    // int num = getListNum(dataList1);
    Data *p = dataList1->next;
    Data *q = dataList1;

    while (p)
    {
        Data *newData = (Data *)malloc(sizeof(Data));
        newData->number = aimNum;

        if (p->number >= aimNum)
        {
            q->next = newData;
            newData->next = p;

            p = q->next;

            q = newData;

            break;
        }

        
        q = p;
        p = p->next;

        if (!p)
        {
            newData->next = p;
            q->next = newData;
        }
    }
}

DataList MergeList(Data *dataList1, Data *dataList2, BOOL isSort)
{
    // ��ȡdataList2�ĸ���
    int num1 = getListNum(dataList1);
    int num2 = getListNum(dataList2);
    Data *p = dataList2->next;
    for (int i = 0; i < num2 && p; i++, p = p->next)
    {
        //�ж�2�е�Ԫ����1���Ƿ����
        if (!isSort)
        {
            if (isExiest(dataList1, p->number))
            {
                continue; // ������������
            }
        }

        if (isSort)
        {
            inserList(dataList1, p->number);
            continue;
        }

        // ���������򽫸�ֵ�����1��
        inserListForNum(dataList1, p->number);
    }
}

void printList(DataList dataList1)
{
    Data *p = dataList1->next;

    while (p)
    {
        printf("\n%u\n", p->number);
        p = p->next;
    }
}



// test1 ���Ա�ĺϲ�
// ���Ա�1��1��3��5��7, 9�����Ա�2��2,4,6,8, 10, 11��
// ������ϲ�Ϊ��3��1234567891011��
// ע��������ʽ

int main()
{
    int a[] = {1, 3, 5, 7, 9};
    int b[] = {12, 3, 14,2 ,6, 8, 22, 11};
    // Data* dataList1 = CreatDataList_Head(a, sizeof(a) / sizeof(a[0]));
    // Data* dataList2 = CreatDataList_Tail(b, sizeof(b) / sizeof(b[0]));

    Data* dataList3 = CreatDataList_Tail(a, sizeof(a) / sizeof(a[0]));
    Data* dataList4 = CreatDataList_Head(b, sizeof(b) / sizeof(b[0]));

    // MergeList(dataList1, dataList2, FALSE);
    MergeList(dataList3, dataList4, TRUE);


    // printList(dataList1);

    printList(dataList3);


    return 0;
}