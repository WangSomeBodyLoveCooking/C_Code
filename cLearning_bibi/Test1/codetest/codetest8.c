// 2.写一个函数，实现一个整形有序数组的二分查找
#include "codetest.h"
int main()
{
    int array[5] = {1, 2, 3, 4, 5};
    int number = sizeof(array) / sizeof(array[0]);
    int n; //需要查找的数
    scanf("%d", &n);
    if(function2(array, number, n))
    {
        printf("找到了，在第%d个元素", function2(array, number, n));
        return 0;
    }
    printf("没找到");
    return 0;
}

//找到了返回索引，找不到返回0
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