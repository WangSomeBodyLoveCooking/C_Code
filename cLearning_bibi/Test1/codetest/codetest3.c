//C语言试题二之计算并输出下列多项式值s=1+1/(1+2)+1/(1+2+3)+..1/(1+2+3…+50)

#include <stdio.h>
#include <math.h>
double Function(int);
int main()
{
    int n;
    scanf("%d", &n);
    printf("请输入n");
    printf("%lf", Function(n));
    return 0;
}

double Function(int n)
{
    int i;
    double sum = 0.0;
    double addOfSum = 0.0;
    for (i = 1; i <= n; i++)
    {
        sum += sqrt(i);
        addOfSum += sum;
    }
    return addOfSum;
}