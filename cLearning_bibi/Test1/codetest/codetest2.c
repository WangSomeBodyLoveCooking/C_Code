//C语言试题二之计算并输出下列多项式值s=1+1/(1+2)+1/(1+2+3)+..1/(1+2+3…+50)

#include <stdio.h>

double function1();
double function2();
int main()
{
    printf("%lf", function1());
    printf("\n%lf\n", function2());
    return 0;
}

double function1()
{
    int i, n = 50;
    int sum = 0;
    double doublesum = 0.0;
    for(i = 1;i <= 50;i++)
    {
        sum += i;
        doublesum += 1.0/sum;
    }

    return doublesum;
}

double function2()
{
    int i, n =50, j;
    int sum = 0;
    double doublesum = 0.0;
    for(i = 1;i <= n;i++)
    {
        sum = 0;
        for(j = 1;j <= i;j++)
        {
            sum += j;
        }
        doublesum += 1.0/sum;
    }
    return doublesum;
}