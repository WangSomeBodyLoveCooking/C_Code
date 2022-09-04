// 结构体案例
/*
学校正在做毕业设计，每个老师带领五个学生，总共有3名老师，需求如下：
设计学生和老师的结构体，其中在老师的结构体中，有老师的姓名和一个存放
5名学生的数组作为成员；
学生的成员有姓名、考试分数，创建数组存放3名老师，通过函数给每个老师
和所带的学生赋值，最终打印出老师数据及老师所带的学生数据。
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
    string teaName = "老师_";
    string stuName = "学生_";
    char array[] = "ABCDE";
    //初始化姓名
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
    //添加随机数种子
    srand((unsigned int)time(NULL));
    //1. 创建老师结构体数组
    Teacher teaArray[3];
    int len = sizeof(teaArray) / sizeof(teaArray[0]);
    int stuLen = sizeof(teaArray->stuArray) / sizeof(teaArray->stuArray[0]);
    //2. 初始化结构体；
    Initiate(teaArray, len, stuLen);

    //3. 打印结构体；
    PrintteaArray(teaArray, len, stuLen);
}