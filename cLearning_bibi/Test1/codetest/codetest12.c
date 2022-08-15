//求第n个斐波那契数

#include "codetest.h"

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", function12_1(n));
    printf("%d", function12_2(n));
    return 0;
}

int function12_1(int n)
{
    if(n <= 2)
    {
        return 1;
    }else 
    {
        return function12_1(n - 1) + function12_1(n -2);
    }
}

int function12_2(int n)
{
    int pre = 1, next, result = 1;
    while(n > 2)
    {
        n--;
        next = pre;
        pre = result;
        result = pre + next;
    }
    return result;
}