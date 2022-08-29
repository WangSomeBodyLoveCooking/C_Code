// 编写代码实现：求一个整数存储在内存中的二进制中1的个数
#include "codetest.h"

int main()
{
    int a = 13;
    printf("%d", funC(a));
    return 0;
}

int funC(int a)
{
    int b = 1;
    int c = 0;
    int court = 0;
    while(a != 0)
    {
        c = a & b;
        if (1 == c)
        {
            court++;
        }
        a >>= 1;
    }
    return court;
}