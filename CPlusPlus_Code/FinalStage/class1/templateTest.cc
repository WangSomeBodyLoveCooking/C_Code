#include <iostream>
using namespace std;
//ʹ��ģ��ʵ��char�����int���������ѡ������

template <typename T>   //��ӡģ��
void prinfFunc(T *a, int len)
{
    for(int i = 0;i < len;i++)
    {
        cout << a[i] << '\t';
    }
    cout << endl;
}

template <typename T>   //����ģ��
void swapFunc(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>   //����ģ��
void sortFunc(T *a, int len)
{
    int max = 0;
    for(int i = 0;i < len; i++)
    {
        max = i;
        for(int j = i + 1;j < len;j++)
        {
            if(a[max] < a[j])
            {
                max = j;
            }
        }

        if(max != i)
        {
            //����max��i
            swapFunc(a[max], a[i]); //ֻ�����Զ������Ƶ�
        }
    }
}

void test()
{
    char a[] = {'b', 'c', 'a', 'e', 'd', 'f'};
    int len = sizeof(a) / sizeof(a[0]);
    sortFunc(a, len);
    prinfFunc(a, len);

    int b[] = {2, 3, 1, 6, 4, 5};
    int intLen = sizeof(b) / sizeof(b[0]);

    sortFunc(b, intLen);
    prinfFunc(b, intLen);
}

int main()
{
    test();
    system("pause");
    return 0;
}