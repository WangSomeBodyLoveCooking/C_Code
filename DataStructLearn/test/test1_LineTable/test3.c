// ͼ�����ϵͳ�����ͼ�����ɾ�Ĳ�
//ʹ������ʽ
#include "test.h"

#define MAX_BOOK_NAME 10

typedef struct Book
{
    char name[MAX_BOOK_NAME];
    float price;
    int freeNum;
}Book;

typedef struct BookList
{
    Book a;
    struct BookList* next;
}BookList;

int main ()
{
    BookList *Head = (BookList*)malloc(sizeof(BookList));
    Head->next = NULL;

    

    return 0;
}