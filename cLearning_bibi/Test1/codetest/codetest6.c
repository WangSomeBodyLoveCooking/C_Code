//��Ŀ���� 1��2��3��4 �ĸ����֣�����ɶ��ٸ�������ͬ�����ظ����ֵ���λ�������Ƕ��٣�

#include <stdio.h>
void function();
int main()
{
    function();
    return 0;
}

void function()
{
    int i, j, k;
    int court;
    for(i = 1;i < 5;i++)
    {
        for(j = 1;j < 5;j++)
        {
            for(k = 1;k < 5;k++)
            {
                if(i != j && i != k && j != k)
                {
                    printf("%d%d%d\n", i, j, k);
                    court++;
                }
            }
        }
    }
    printf("\nһ��%d��", court);
    return;
}