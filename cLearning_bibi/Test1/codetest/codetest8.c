// 2.дһ��������ʵ��һ��������������Ķ��ֲ���
#include "codetest.h"
int main()
{
    int array[5] = {1, 2, 3, 4, 5};
    int number = sizeof(array) / sizeof(array[0]);
    int n; //��Ҫ���ҵ���
    scanf("%d", &n);
    if(function2(array, number, n))
    {
        printf("�ҵ��ˣ��ڵ�%d��Ԫ��", function2(array, number, n));
        return 0;
    }
    printf("û�ҵ�");
    return 0;
}

//�ҵ��˷����������Ҳ�������0
int function2(int array[], int number, int n)
{
    int head = 0, end = number - 1;
    int middle;
    while (head <= end)
    {
        middle = (head + end) / 2;
        if (array[middle] > n)
        {
            end = middle - 1;
        }
        else if (array[middle] < n)
        {
            head = middle + 1;
        }
        else
        {
            return middle + 1;
        }
    }
    return 0;
}