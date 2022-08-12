// C语言试题五之计算并输出给定数组(长度为9)中每相邻两个元素之平均值的平方根之和

#include <stdio.h>
#include <math.h>

double Function(int *array, int n)
{
    if(NULL == array)
    {
        return -1;
    }
    int i = 0, j = 1;
    double sum = 0.0;
    for (; j < n; i++, j++)
    {
        sum += sqrt((*(array + i) + *(array + j)) / 2.0);   //这里一定要除以2.0，不然(*(array + i) + *(array + j)) / 2.0可能第一次计算为1
    }
    return sum;
}

int main()
{
    int array[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    double sum;
    int n = sizeof(array) / sizeof(array[0]);
    sum = Function(array, n);
    printf("%lf", sum);
    return 0;
}
