//��n�Ľ׳�

#include "codetest.h"

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", function11(n));
    printf("\n%d", function11_1(n));
    return 0;
}

int function11(int n) //����д��
{
    int i;
    int sum = 1;
    for(i = 1;i <= n;i++)
    {
        sum *= i;
    }
    return sum;
}

int function11_1(int n)
{
    if(1 == n)
    {
        return 1;
    }else
    {
        return n * function11_1(n - 1);
    }
   
}