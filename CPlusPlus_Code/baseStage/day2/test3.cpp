//ð������
#include <iostream>

using namespace std;

int main()
{
    int a[8] = {4, 43, 21, 234, 1, 3, 43, 5};
    int num = sizeof(a) / sizeof(*(a + 1));
    //1. ��ӡ
    for(int i = 0;i < num;i++)
    {
        cout << *(a + i) << ' ';
    }
    cout << endl;

    // 2. ð������
    bool flag = true;
    for(int i = 0;i < num;i++)
    {
        for(int j = 0;j < num - i - 1;j++)
        {
            //�ж�������Ԫ���Ƿ�˳���С��ͬ
            if(a[j] > a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                flag = false;
            }
        }
        if(flag)    // �����Ч��
        {
            break;
        }
    }

    //3. ��ӡ�����
    for(int i = 0;i < num;i++)
    {
        cout << a[i] << " ";
    }
    system("pause");
    return 0;
}