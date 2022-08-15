//1.写一个函数可以判断一个数是不是素数？？

#include "codetest.h"
int main()
{
    int n;
    scanf("%d", &n);
    if(function1(n))
    {
        printf("%d是素数", n);
    }
    printf("%d不是素数", n);
    return 0;
}

//判断一个数是否为素数，若是返回1，不是返回0
int function1(int n)
{
    int i;
    for(i = 2;i <= sqrt(n);i++)
    {
        if(n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}



