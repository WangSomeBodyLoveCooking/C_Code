//函数模板与普通函数的调用规则：
//1. 普通函数与函数模板都可以实现，则优先调用普通函数
//2. 可以使用空模板参数列表，强制调用函数模板
//3. 函数模板也可以发生重载
//4. 如果函数模板拥有更好的匹配度，则调用函数模板
//注：既然有了函数模板，就尽量不要提供普通函数，防止二义性

//若在普通函数优先情况下，普通函数缺少实现，则也不会调用函数模板，会在链接阶段报缺少函数定义错误！
#include <iostream>
using namespace std;

void printFunc(int a, int b)
{
    cout << "调用普通函数" << endl;
}

template <typename T>
void printFunc(T a, T b)
{
    cout << "调用函数模板" << endl;
}

template <typename T>
void printFunc(T a, T b, T c)
{
    cout << "调用函数模板" << endl;
}

void test()
{
    int a = 10;
    int b = 10;
    int c = 10;
    printFunc(a, b);    // 普通函数与函数模板都可以实现时，优先调用普通函数；
    printFunc<>(a, b);  // 可以使用空模板参数列表，强制调用函数模板；
    printFunc<int>(a, b, c);    //函数模板也可以发生重载；
    
    char e = 'e';
    char d = 'd';
    printFunc<char>(e, d);  //函数模板具有更好匹配度时，优先调用函数模板
}

int main()
{
    test();
    system("pause");
    return 0;
}