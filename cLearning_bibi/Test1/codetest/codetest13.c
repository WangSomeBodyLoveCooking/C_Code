//×Ö·û´®ÄæĞò£ºÈçchar *array = "abcdef"  ÄæĞòºóÎª"fedcba"
#include "codetest.h"

int main()
{
    char array[] = "abcdef";
    printf("%s", array);
    printf("\n%d\n", my_strlen(array));
    resortStr1(array);
    printf("\n%s\n", array);
    resortStr2(array);
    printf("\n%s\n", array);
    return 0;
}

int my_strlen(char *array)
{
    if (*array != 0)
    {
        return 1 + my_strlen(array + 1);
    }
    else
    {
        return 0;
    }
}

void resortStr1(char *array)
{
    int len = my_strlen(array);
    char temp = ' ';
    int head = 0;
    int end = len - 1;
    while (head < end)
    {
        temp = *(array + head);
        *(array + head) = *(array + end);
        *(array + end) = temp;
        head++;
        end--;
    }
    return;
}

void resortStr2(char *array)
{
    int len = my_strlen(array);
    char temp = ' ';
    int head = 0;
    int end = len - 1;
    temp = *(array);
    *(array) = *(array + end);  //2
    *(array + end) = 0;     //3
    if (1 < my_strlen(array + 1))
    {
        resortStr1(array + 1);      //4
    }
    *(array + end) = temp;      //5
}
