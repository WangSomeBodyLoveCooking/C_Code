//1.�ڴ����
//��������ȫ������ջ���Ͷ���
//�������ǹ���ֻ���ģ��ɲ���ϵͳ���й���
#include <stdio.h>

//ȫ��������
int a = 0;  // ȫ�ֱ���
const int b = 0;    // ȫ�ֳ���
static int e = 0;   // ��̬����
void testGlb()
{
    int c = 0;  // �ֲ�����
    const int d = 0;    // �ֲ�����
    static int f = 0;   // ��̬����
    printf("%x\n", &a);         // 407030
    printf("%x\n", &b);         // 404000
    printf("%x\n", &c);         // 61fdec
    printf("%x\n", &d);         // 61fde8
    printf("%x\n", "hello");    // 404008
    printf("%x\n", &e);         // 407034
    printf("%x\n", &f);         // 407038

    // �ӽ�����Կ�����ȫ���������ȫ�ֱ�������̬������������ȫ�ֳ������ַ���������
}

int* testZhan()
{
    int x = 0;
    // int *x = new int(10);
    return &x;  //��Ҫ���ؾֲ������ĵ�ַ
}

int* testHeap()
{
    int *x = new int[10];   // new�ؼ��֣����ض�Ӧ���͵�ָ��
    return x;
}

int main()
{
    testGlb();
    int *y = NULL;
    // y = testZhan();  //��Ҫ���ؾֲ������ĵ�ַ
    y = testHeap();
    printf("%d", *y);
    delete y;   //�ڶ��������ڴ��Ҫ�ǵ��ͷ�

    return 0;
}