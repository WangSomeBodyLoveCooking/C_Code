//ð������
#include "codetest.h"
int main()
{
    int num;
    int x;
    int array[10] = {1, 4, 3, 5, 7, 23, 12, 432, 3, 15};
    num = sizeof(array) / sizeof(array[0]);
    BobbleSort(array, num);
    for(x = 0;x < num;x++)
    {
        printf("%d,", array[x]);
    }
    return 0;
}

void BobbleSort(int *array, int num)
{
    int i, j; 
    int temp = 0;
    int flag = 1;
    for(i = 0;i < num - 1;i++)  //num - 1�ֱȽ�
    {
        for(j = 0;j < num - 1 -i;j++)   //ÿ�ֱȽ�num -1 -i��
        {
            if(array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                flag = 0;
            }
        }
        if (1 == flag)      //��û��ִ�й�����������������������
        {
            break;      
        }
    }
    return;
}