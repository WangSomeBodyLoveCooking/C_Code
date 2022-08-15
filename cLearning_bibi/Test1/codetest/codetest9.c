//接受一个整形值（无符号），按照顺序打印它的每一位。
#include "codetest.h"

int main()
{
    int n;
    scanf("%d", &n);
    function9(n);
    function(n);
    return 0;
}

void function9(int n) //反向打印，如123打印321
{
    if (n > 0)
    {
        printf("%d", n % 10);
        function9(n / 10);
    }
    return;
}

void function(int n)        //递归方法
{
    if (n > 9)
    {
        function(n / 10);
    }
    printf("%d", n % 10);
}