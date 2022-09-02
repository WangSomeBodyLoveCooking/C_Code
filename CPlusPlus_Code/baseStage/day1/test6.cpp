// c++从键盘输入 cin >> 变量

#include <iostream>

using namespace std;

int main()
{
    //1.输入int
    int a = 0;
    cout << "请输入a值" << endl;
    cin >> a;
    cout << a << endl;
    //2. 输入浮点型
    float b = 3.14f;
    cout << "请输入float值" << endl;
    cin >> b;
    cout << b << endl;
    //3. 输入字符型
    char c = 'a';
    cout << "请输入c值" << endl;
    cin >> c;
    cout << c << endl;
    //4. 输入字符串型
    string d = "abcdef";
    cout << "请输入string值" << endl;
    cin >> d;
    cout << d << endl;
    //5. 输入比尔型
    bool f = false;
    cout << "请输入bool值" << endl;
    cin >> f;
    cout << f << endl;

    system("pause");
    return 0;
}