//���ܴ�����ʱ������ʵ���������Ľ�����
#include "codetest.h"

int main()
{
    int a = 1, b = 2;
    ex_num1(&a, &b);
    printf("%d %d\n", a, b);
    ex_num2(&a, &b);
    printf("%d %d\n", a, b);
    ex_num3(&a, &b);
    printf("%d %d\n", a, b);
    return 0;
}

//��ͳ�ķ�����
void ex_num1(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}

//������:   //�÷������ܻ����int��Χ���
void ex_num2(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
    return;
}

//��������  // a ^ 0 == a   a ^ a = 0
void ex_num3(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;   //�൱��a ^ b ^ b
    *a = *a ^ *b;
    return;
}