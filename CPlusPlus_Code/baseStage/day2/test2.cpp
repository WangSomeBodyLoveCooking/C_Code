// �˷��ھ���
#include <iostream>

using namespace std;

int main()
{
    //1. ��ӡ����
    for(int i = 1;i <= 9;i++)
    {
        //2. ��ӡ����
        for(int j = 1;j <= i;j++)
        {
            cout << j << "x" << i << "=" << i*j << ' ';
        }
        cout << endl;
    }
    system("pause");
    return 0;
}
