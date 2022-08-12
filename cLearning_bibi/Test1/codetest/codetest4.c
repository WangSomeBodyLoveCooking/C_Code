// C语言试题四之计算并输出3到n之间所有素数的平方根之和

#include <stdio.h>
#include <math.h>
void Function(int n);
int main()
{
    int n;
    scanf("%d", &n);
    Function(n);
    return 0;
}

void Function(int n)
{
    int i, j;
    double sum = 0.0;
    int court = 0;
    for (i = 3; i <= n; i += 2)
    {
        for (j = 2; j <= sqrt(i); j++)  //通过j <= sqrt(i)提高了计算效率
        {
            if (i % j == 0)
            {
                break;
            }
        }
        if (j > sqrt(i))    //判断是否为素数的关键条件
        {
            printf("%d\n", i);
            sum += sqrt(i);
            court++;
        }
    }

    printf("\n素数平方根和为%lf,素数个数为%d", sum, court);
    return;
}
