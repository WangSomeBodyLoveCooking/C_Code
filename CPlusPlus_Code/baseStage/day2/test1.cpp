// ������
#include <iostream>
using namespace std;
#include <ctime>

int main()
{
    //������������  ���ã����õ�ǰϵͳʱ���������������ֹÿ���������һ��
    srand((unsigned int)time(NULL));
    // 1. ����һ�������
    int randNum = rand() % 100 + 1;
    // rand()%100   ����һ��0~99�������
    // 2. ����һ������
    int num = 0;
    while (1)
    {
        cin >> num;
        // 3. �ж������Ǵ��˻���С�˻���һ��
        if (num > randNum)
        {
            cout << "����" << endl;
        }
        else if (num < randNum)
        {
            cout << "С��" << endl;
        }
        else
        {
            cout << "�¶���" << endl; 
            break;
        }
    }
    system("pause");
    return 0;
}