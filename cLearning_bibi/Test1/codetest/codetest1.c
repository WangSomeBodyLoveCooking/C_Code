/*
C��������һ֮���㲢���n(����n)�����ܱ�5��9������������Ȼ���ĵ���֮��
*/

#include <stdio.h>

double function(int);
int main()
{
    int n;
    double sum1;
    scanf("%d", &n);
    sum1 = function(n);
    printf("%f", sum1);
    return 0;
}

double function(int n)
{
    int i;
    double sum = 0.0;
    for(i = 1;i <= n;i++)
    {
        if(i % 5 == 0 || i % 9 == 0)
        {
            sum += 1.0 / i;
        }
    }
    return sum;
}