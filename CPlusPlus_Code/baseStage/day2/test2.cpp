// 乘法口诀表
#include <iostream>

using namespace std;

int main()
{
    //1. 打印行数
    for(int i = 1;i <= 9;i++)
    {
        //2. 打印列数
        for(int j = 1;j <= i;j++)
        {
            cout << j << "x" << i << "=" << i*j << ' ';
        }
        cout << endl;
    }
    system("pause");
    return 0;
}
