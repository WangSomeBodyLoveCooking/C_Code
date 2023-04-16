//使用模板实现char数组和int数组的排序（冒泡排序）
#include <iostream>
using namespace std;

template <typename T>
void printFunc(T a[], int len)
{
    for(int x = 0;x < len;x++)
    {
        cout << a[x] << '\t';
    }
    cout << endl;
}

template <typename T>
void switchFunc(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void sortFunc(T * c, int len)
{
    for(int i = 0;i < len - 1;i++)
    {
        for(int j = 0;j < len - i - 1;j++)
        {
            if(c[j] > c[j+1])
            {
                switchFunc(c[j], c[j+1]);
            }
        }
    }
}


void test()
{
    // char c[] = {'v', 'c', 'd', 'a', 'b', 'x', 'e'};
    // int cLen = sizeof(c) / sizeof(c[0]);
    // sortFunc(c, cLen);
    // printFunc(c, cLen);

    int i[] = {3, 4, 2, 5, 1, 6, 22, 12};
    int iLen = sizeof(i) / sizeof(i[0]);
    sortFunc(i, iLen);
    printFunc(i, iLen);

}

int main()
{
    test();
    system("pause");
    return 0;
}