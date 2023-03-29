#include <iostream>
using namespace std;

//3. 引用做函数参数（相当于地址传递）
void func(int &b)
{
    b++;
    return;
}

//4.引用做函数返回值（1.不要返回局部变量的引用，2.函数可有做左值）
int& fun()
{
    int a = 0;
    return a;
}

int main()
{
    //1.引用的定义
    int a = 0;
    int &b = a; //引用必须初始化,且初始化后不可改变
    // int &c; //error
    int c = 100;
    b = c;  //不是改变引用，而是赋值操作
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;  //三个100

    func(a);
    cout << a << endl;  //101

    int &e = fun();  //不要返回局部变量的引用
    cout << e << endl;  //随机值或error

    fun() = 100;  //函数做左值
    cout << e << endl;  



//5. 引用的本质
    int &x = a; // 编译器处理 int *const x = &a;    为一个指针常量
    x = 20; // 编译器处理 *a = 20;

//6. 常量的引用
    // int &y = 10;    // error 引用必须指向合法的内存空间（栈区或堆区）
    const int &y = 10; //这是合法的
    function(10);   //这是合法的
    system("pause");
    return 0;
}

void function(const int &a) //即 常量引用
{

}