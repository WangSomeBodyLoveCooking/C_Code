// �ṹ�尸��
/*
ѧУ��������ҵ��ƣ�ÿ����ʦ�������ѧ�����ܹ���3����ʦ���������£�
���ѧ������ʦ�Ľṹ�壬��������ʦ�Ľṹ���У�����ʦ��������һ�����
5��ѧ����������Ϊ��Ա��
ѧ���ĳ�Ա�����������Է���������������3����ʦ��ͨ��������ÿ����ʦ
��������ѧ����ֵ�����մ�ӡ����ʦ���ݼ���ʦ������ѧ�����ݡ�
*/
#include "test.h"

struct Student
{
    string studentName;
    int score;
};

struct Teacher
{
    string teacherName;
    struct Student stuArray[5];
};

void Initiate(struct Teacher *teaArray, int len, int stuLen)
{
    string teaName = "��ʦ_";
    string stuName = "ѧ��_";
    char array[] = "ABCDE";
    //��ʼ������
    for(int i = 0;i < len;i++)
    {
       teaArray[i].teacherName = teaName;
       teaArray[i].teacherName += array[i];
       for(int j = 0;j < stuLen;j++)
       {
            teaArray[i].stuArray[j].studentName = stuName;
            teaArray[i].stuArray[j].studentName += array[j];
            teaArray[i].stuArray[j].score = rand() % 101;
       }
    }
}

void PrintteaArray(Teacher *teaArray, int len, int stuLen)
{
    for(int i = 0;i < len;i++)
    {
        cout << (teaArray + i)->teacherName << endl;
        for(int j = 0;j < stuLen;j++)
        {
            // cout << (teaArray + i)->(stuArray + j)->studentName << endl;
            cout << "\t" << (teaArray + i)->stuArray[j].studentName << " ";
            cout << (teaArray + i)->stuArray[j].score << endl;
        }
        
    }
}

int main()
{
    //������������
    srand((unsigned int)time(NULL));
    //1. ������ʦ�ṹ������
    Teacher teaArray[3];
    int len = sizeof(teaArray) / sizeof(teaArray[0]);
    int stuLen = sizeof(teaArray->stuArray) / sizeof(teaArray->stuArray[0]);
    //2. ��ʼ���ṹ�壻
    Initiate(teaArray, len, stuLen);

    //3. ��ӡ�ṹ�壻
    PrintteaArray(teaArray, len, stuLen);
}