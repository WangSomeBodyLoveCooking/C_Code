//��Ŀ���� 1��2��3��4 �ĸ����֣�����ɶ��ٸ�������ͬ�����ظ�����(�����λ����ÿһλ����һ��)����λ�������Ƕ��٣�
#include "test.h"

int main()
{
    int a = 0;
    int x = 0;
    for(int i = 1;i <= 4;i++)
    {
        for(int j = 1;j <= 4;j++)
        {
            for(int k = 1;k <= 4;k++)
            {
                if(i == k || i == j || j == k)
                {
                    continue;
                }
                x++;
                a = i * 100 + j * 10 + k;
                cout << a << endl;
            }
        }
    }
    system("pause");
    return 0;
}