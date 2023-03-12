#include "test.h"

void BubbleSort(int * arr, int num)
{
    for(int i = 0;i < num - 1;i++)
    {
        for(int j = 0;j < num - i -1;j++)
        {
            if(*(arr + j) > *(arr + j + 1))
            {
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }

    cout << "[";
    for(int i = 0;i < num;i++)
    {
        cout << *(arr + i);
        if(num - 1 == i)
        {
            cout << "]";
        }
        else
        {
            cout << ",";
        }
    }

}