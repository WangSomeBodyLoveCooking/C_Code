// 猜数字
#include <iostream>
using namespace std;
#include <ctime>

int main()
{
    //添加随机数种子  作用：利用当前系统时间生成随机数，防止每次随机数都一样
    srand((unsigned int)time(NULL));
    // 1. 生成一个随机数
    int randNum = rand() % 100 + 1;
    // rand()%100   生成一个0~99的随机数
    // 2. 输入一个数字
    int num = 0;
    while (1)
    {
        cin >> num;
        // 3. 判断数字是大了还是小了还是一样
        if (num > randNum)
        {
            cout << "大了" << endl;
        }
        else if (num < randNum)
        {
            cout << "小了" << endl;
        }
        else
        {
            cout << "猜对了" << endl; 
            break;
        }
    }
    system("pause");
    return 0;
}