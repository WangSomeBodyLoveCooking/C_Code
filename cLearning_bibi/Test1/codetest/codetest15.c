//不能创建临时变量，实现两个数的交换。
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

//传统的方法：
void ex_num1(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}

//方法二:   //该方法可能会造成int范围溢出
void ex_num2(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
    return;
}

//方法三：  // a ^ 0 == a   a ^ a = 0
void ex_num3(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;   //相当于a ^ b ^ b
    *a = *a ^ *b;
    return;
}