#include <iostream>
using namespace std;

#define DAY 7
int main()
{
    //定义常量方式：1. 宏定义的标识符常量 2.const修饰的常变量
    //1.
    //  DAY = 3;  error  报错
    cout << "一周一共有" << DAY << "天"  << endl;
    //2.
    const int year = 12;
    // year = 13;   error  报错
    cout << "一年一共有" << year << "月" << endl;
    system("pause");
    return 0;
}