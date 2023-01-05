#include <iostream>
//1.包含头文件
#include <fstream>

using namespace std;

void test()
{
    //2. 创建流对象
    ofstream ofs;

    //3. 打开文件
    ofs.open("test.txt", ios::out);

    //4. 写内容
    ofs << "姓名：张三" << endl;
    ofs << "性别：男" << endl;
    ofs << "年龄：20" << endl;

    //5. 关闭文件
    ofs.close();
}

int main()
{
    test();
    system("pause");
    return 0;
}