// C++字符串类型
#include <iostream>
using namespace std;

int main()
{
    //1. c语言的字符串
    char array[] = "abcdef";
    cout << array << endl;
    char *a = "abcdefg";
    // cout << *a << "\n" << endl;

    //2. c++ 的字符串 需要包含string库
    string array1 = "abcdef";
    cout << array1 << endl;
    system("pause");
    return 0;
}