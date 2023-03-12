#include <iostream>
#include "test.h"
using namespace std;

int main()
{
    int a[] = {5, 43, 3, 2, 56, 32, 7, 38, 123, 1};
    int num = sizeof(a) / sizeof(a[0]);
    BubbleSort(a, num);
    system("pause");
    return 0;
}