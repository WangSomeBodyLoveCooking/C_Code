// c++�Ӽ������� cin >> ����

#include <iostream>

using namespace std;

int main()
{
    //1.����int
    int a = 0;
    cout << "������aֵ" << endl;
    cin >> a;
    cout << a << endl;
    //2. ���븡����
    float b = 3.14f;
    cout << "������floatֵ" << endl;
    cin >> b;
    cout << b << endl;
    //3. �����ַ���
    char c = 'a';
    cout << "������cֵ" << endl;
    cin >> c;
    cout << c << endl;
    //4. �����ַ�����
    string d = "abcdef";
    cout << "������stringֵ" << endl;
    cin >> d;
    cout << d << endl;
    //5. ����ȶ���
    bool f = false;
    cout << "������boolֵ" << endl;
    cin >> f;
    cout << f << endl;

    system("pause");
    return 0;
}