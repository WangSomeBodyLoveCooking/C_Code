#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char name[20];
    int price;
}Book, *ptBook;

//˳��ջ
typedef struct
{
    ptBook base;
    ptBook top;
    int stackSize;
}Stack, *ptStack;

//��ջ
typedef struct StackNode
{
    ptBook book;
    struct StackNode *next;
}StackNode, *ptStackNode;

#define STACKSIZE 100
#define TRUE 1
#define FALSE 0
//�ٳ�ʼ��ջ
int InitStack(Stack *stack)
{
    stack->base = (Book *)malloc(STACKSIZE * sizeof(Book));

    if (NULL == stack->base)
    {
        return FALSE;
    }

    stack->top = stack->base;
    stack->stackSize = STACKSIZE;
    
    return TRUE;
}

int InitStackLian(ptStackNode stacknode)
{
    stacknode = NULL;
    return TRUE;
}

//����ջ�ĳ���
int GetStackLen(Stack *stack)
{
    int a = stack->top - stack->base;
    return a;
}

int GetStackLenLian(ptStackNode stacknode)
{
    StackNode *p = stacknode;
    int nodeNum = 0;
    while (p)
    {
        nodeNum++;
        p = p->next;
    }

    return nodeNum;
}

// ���ж�ջ�Ƿ�Ϊ��
int IsNullStack(Stack *stack)
{
    if (stack->top == stack->base)
    {
        return TRUE;
    }

    return FALSE;
}

int IsNullStackList(ptStackNode stacknode)
{
    if (NULL == stacknode)
    {
        return TRUE;
    }

    return FALSE;

}

//�����ջ
void ClearStack(Stack *stack)
{
    stack->top == stack->base;
}

//������ջ
void DestorStack(Stack *stack)
{
    free(stack->base);
    stack->top = NULL;
    stack->stackSize = 0;
}

void ClearOrDestorStackList(ptStackNode stacknode)
{
    StackNode *p = stacknode;
    StackNode *q = p;
    while (p)
    {
        q = p->next;
        free(p);
        p = q;
    }
}

//�޻�ȡջ��Ԫ��
Book* GetTopStackElement(Stack *stack)
{
    return stack->top;
}

Book* GetTopStackElementList(ptStackNode stacknode)
{
    return stacknode->book;
}

//����ջ
int PopStack(Stack *stack, Book book)
{
    if (stack->stackSize == GetStackLen(stack))
    {
        return FALSE;
    }

    memcpy(stack->top, &book, sizeof(Book));
    stack->top++;
}

int PopStackList(ptStackNode stacknode, Book book)
{
    ptStackNode p = (ptStackNode)malloc(sizeof(StackNode));
    p->book = &book;
    p->next = stacknode;
    stacknode = p;
}

//���ջ
int PushStack(Stack *stack, Book book)
{
    if (stack->top == stack->base)
    {
        return FALSE;
    }

    memcpy(&book, stack->top, sizeof(Book));
    stack->top--;
}

int PushStackList(ptStackNode stacknode, Book book)
{
    if (NULL == stacknode)
    {
        return FALSE;
    }

    book = *stacknode->book;
    ptStackNode p = stacknode->next;
    free(stacknode);
    stacknode = p;
}

int main()
{
    char a[2] = {0};
    char b[10] = {97, 98, 99, 100};
    memcpy(a, b, sizeof(b) );

    printf("%d", a[0]);
    printf("%d", a[1]);
    printf("%d", a[2]);


    Stack a = {0};
    InitStack(&a);
    Book b = {"xiaoshuo", 10};
    PopStack(&a, b);

    printf("len = %u\n", GetStackLen(&a));
    return 0;
}