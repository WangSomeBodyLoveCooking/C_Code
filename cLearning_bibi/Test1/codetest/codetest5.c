// C����������֮���㲢�����������(����Ϊ9)��ÿ��������Ԫ��֮ƽ��ֵ��ƽ����֮��

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
        sum += sqrt((*(array + i) + *(array + j)) / 2.0);   //����һ��Ҫ����2.0����Ȼ(*(array + i) + *(array + j)) / 2.0���ܵ�һ�μ���Ϊ1
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
