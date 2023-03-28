//1.内存分区
//代码区，全局区，栈区和堆区
//代码区是共享只读的，由操作系统进行管理
#include <stdio.h>

//全局区测试
int a = 0;  // 全局变量
const int b = 0;    // 全局常量
static int e = 0;   // 静态变量
void testGlb()
{
    int c = 0;  // 局部变量
    const int d = 0;    // 局部常量
    static int f = 0;   // 静态变量
    printf("%x\n", &a);         // 407030
    printf("%x\n", &b);         // 404000
    printf("%x\n", &c);         // 61fdec
    printf("%x\n", &d);         // 61fde8
    printf("%x\n", "hello");    // 404008
    printf("%x\n", &e);         // 407034
    printf("%x\n", &f);         // 407038

    // 从结果可以看出，全局区存放了全局变量、静态变量、常量（全局常量和字符串常量）
}

int* testZhan()
{
    int x = 0;
    // int *x = new int(10);
    return &x;  //不要返回局部变量的地址
}

int* testHeap()
{
    int *x = new int[10];   // new关键字，返回对应类型的指针
    return x;
}

int main()
{
    testGlb();
    int *y = NULL;
    // y = testZhan();  //不要返回局部变量的地址
    y = testHeap();
    printf("%d", *y);
    delete y;   //在堆区开辟内存后要记得释放

    return 0;
}