//����ģ������ͨ�����ĵ��ù���
//1. ��ͨ�����뺯��ģ�嶼����ʵ�֣������ȵ�����ͨ����
//2. ����ʹ�ÿ�ģ������б�ǿ�Ƶ��ú���ģ��
//3. ����ģ��Ҳ���Է�������
//4. �������ģ��ӵ�и��õ�ƥ��ȣ�����ú���ģ��
//ע����Ȼ���˺���ģ�壬�;�����Ҫ�ṩ��ͨ��������ֹ������

//������ͨ������������£���ͨ����ȱ��ʵ�֣���Ҳ������ú���ģ�壬�������ӽ׶α�ȱ�ٺ����������
#include <iostream>
using namespace std;

void printFunc(int a, int b)
{
    cout << "������ͨ����" << endl;
}

template <typename T>
void printFunc(T a, T b)
{
    cout << "���ú���ģ��" << endl;
}

template <typename T>
void printFunc(T a, T b, T c)
{
    cout << "���ú���ģ��" << endl;
}

void test()
{
    int a = 10;
    int b = 10;
    int c = 10;
    printFunc(a, b);    // ��ͨ�����뺯��ģ�嶼����ʵ��ʱ�����ȵ�����ͨ������
    printFunc<>(a, b);  // ����ʹ�ÿ�ģ������б�ǿ�Ƶ��ú���ģ�壻
    printFunc<int>(a, b, c);    //����ģ��Ҳ���Է������أ�
    
    char e = 'e';
    char d = 'd';
    printFunc<char>(e, d);  //����ģ����и���ƥ���ʱ�����ȵ��ú���ģ��
}

int main()
{
    test();
    system("pause");
    return 0;
}