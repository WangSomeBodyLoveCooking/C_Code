//��д��������������ʱ���������ַ�������

//�ַ������Ⱥ���strlen
#include "codetest.h"

int main()
{
    char a[] = "abced";
    printf("%d", reDefStrlen(a));
    printf("\n%d\n", reDefStrlen1(a));
    return 0;
}

int reDefStrlen(char *a)
{
    int court = 0;
    while (*a++)
    {
        court++;
    }
    return court;
}

int reDefStrlen1(char *a)
{
   if(*a)
   {
       return 1 + reDefStrlen1(a + 1);
   }else
   {
       return 0;
   }
}