#ifndef MAIN
#define MAIN

#include "workerManage.h"

typedef void (*Func)()

struct Menu
{
    char choice;
    Func func;
};

Menu menu[8] = 
{
    {'0', exitSystem},
}

#endif

