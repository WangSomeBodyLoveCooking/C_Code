//1.дһ�����������ж�һ�����ǲ�����������

#include "codetest.h"
int main()
{
    int n;
    scanf("%d", &n);
    if(function1(n))
    {
        printf("%d������", n);
    }
    printf("%d��������", n);
    return 0;
}

//�ж�һ�����Ƿ�Ϊ���������Ƿ���1�����Ƿ���0
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



