//����һ������ֵ���޷��ţ�������˳���ӡ����ÿһλ��
#include "codetest.h"

int main()
{
    int n;
    scanf("%d", &n);
    function9(n);
    function(n);
    return 0;
}

void function9(int n) //�����ӡ����123��ӡ321
{
    if (n > 0)
    {
        printf("%d", n % 10);
        function9(n / 10);
    }
    return;
}

void function(int n)        //�ݹ鷽��
{
    if (n > 9)
    {
        function(n / 10);
    }
    printf("%d", n % 10);
}