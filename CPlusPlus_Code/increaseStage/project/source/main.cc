#include <iostream>
using namespace std;
#include "workerManage.h"
#include "main.h"

int main()
{
    WorkerManage wM;
    char ch = 0;
    while(true)
    {
        wM.showMenu();
        cout << "ÇëÊäÈëÄúµÄÑ¡Ôñ" << endl;
        cin >> ch;
        for(int i = 0;i < sizeof(menu)/sizeof(Menu);i++)
        {
            if(ch == menu[i].choice)
            {
                menu[i].func();
            }
        }

    }
    system("pause");
    return 0;
}