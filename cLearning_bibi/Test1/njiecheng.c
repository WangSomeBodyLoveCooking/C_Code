#include <stdio.h>

int main()
{
    int i;
    int n;
    int sum = 1;    //用来存储n的阶乘
    scanf("%d", &n);
    for(i = 1;i <= n;i++)
    {
        sum *= i;
    }
    printf("%d", sum);
    return 0;
}