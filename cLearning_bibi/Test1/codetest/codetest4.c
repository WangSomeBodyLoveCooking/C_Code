// C����������֮���㲢���3��n֮������������ƽ����֮��

#include <stdio.h>
#include <math.h>
void Function(int n);
int main()
{
    int n;
    scanf("%d", &n);
    Function(n);
    return 0;
}

void Function(int n)
{
    int i, j;
    double sum = 0.0;
    int court = 0;
    for (i = 3; i <= n; i += 2)
    {
        for (j = 2; j <= sqrt(i); j++)  //ͨ��j <= sqrt(i)����˼���Ч��
        {
            if (i % j == 0)
            {
                break;
            }
        }
        if (j > sqrt(i))    //�ж��Ƿ�Ϊ�����Ĺؼ�����
        {
            printf("%d\n", i);
            sum += sqrt(i);
            court++;
        }
    }

    printf("\n����ƽ������Ϊ%lf,��������Ϊ%d", sum, court);
    return;
}
