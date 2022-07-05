#include <stdio.h>

int main()
{
    //sizeof为关键字，计算变量或常量所占字节大小
    printf("%d\n", sizeof(int)); 
    printf("%d\n", sizeof(char));
    printf("%d\n", sizeof(short));
    printf("%d\n", sizeof(long)); //C标准规定sizeof(long) >= sizeof(int)
    printf("%d\n", sizeof(long long));
    printf("%d\n", sizeof(float));
    printf("%d\n", sizeof(double));
    return 0;
}