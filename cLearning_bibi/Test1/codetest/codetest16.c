// ��д����ʵ�֣���һ�������洢���ڴ��еĶ�������1�ĸ���
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