//冒泡排序
#include <iostream>

using namespace std;

int main()
{
    int a[8] = {4, 43, 21, 234, 1, 3, 43, 5};
    int num = sizeof(a) / sizeof(*(a + 1));
    //1. 打印
    for(int i = 0;i < num;i++)
    {
        cout << *(a + i) << ' ';
    }
    cout << endl;

    // 2. 冒泡排序
    bool flag = true;
    for(int i = 0;i < num;i++)
    {
        for(int j = 0;j < num - i - 1;j++)
        {
            //判断两相邻元素是否顺序大小不同
            if(a[j] > a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                flag = false;
            }
        }
        if(flag)    // 可提高效率
        {
            break;
        }
    }

    //3. 打印排序后
    for(int i = 0;i < num;i++)
    {
        cout << a[i] << " ";
    }
    system("pause");
    return 0;
}