//题目：有 1、2、3、4 四个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？

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
    printf("\n一共%d个", court);
    return;
}