#include <iostream>
//1.����ͷ�ļ�
#include <fstream>

using namespace std;

void test()
{
    //2. ����������
    ofstream ofs;

    //3. ���ļ�
    ofs.open("test.txt", ios::out);

    //4. д����
    ofs << "����������" << endl;
    ofs << "�Ա���" << endl;
    ofs << "���䣺20" << endl;

    //5. �ر��ļ�
    ofs.close();
}

int main()
{
    test();
    system("pause");
    return 0;
}