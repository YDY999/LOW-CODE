#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100
#define STACKINCREAMENT 10
//#define size 20;
typedef char SElementType;

typedef struct stack {
    SElementType *base;
    SElementType* top;
    int stacksize;
}SqStack;

int Stack_Init(SqStack &S);
int Stack_Push(SqStack& S, SElementType e);
int Stack_Pop(SqStack& S, SElementType &e_1);
int Stack_Empty(SqStack S);
int Stack_Print(SqStack S);
int Matching(SqStack& S, char* str);
char Pairs(char ch);

int main()
{
    SqStack S;
    char ch[20];
    int a;
    scanf("%s", ch);
    Stack_Init(S);
    a = Matching(S, ch);
    if (a == 1)
        printf("Matching!\n");
    else
        printf("Mismatching!\n");
    return 0;
}

int Stack_Init(SqStack &S)
{
    S.base = (SElementType*)malloc(STACK_INIT_SIZE * sizeof(SElementType));
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return 0;
}

int Stack_Push(SqStack &S , SElementType e)
{
    if (S.top - S.base >= S.stacksize)  //栈满
    {
        S.base = (SElementType*)realloc(S.base, (S.stacksize + STACKINCREAMENT) * sizeof(SElementType));
        S.top = S.base + S.stacksize;
        S.stacksize += STACKINCREAMENT;
    }
    *S.top++ = e;
    return 0;
}

int Stack_Pop(SqStack& S, SElementType& e_1)
{
    if (S.top == S.base)
        return -1;
    e_1 = *--S.top;
    return 0;
}

int Stack_Print(SqStack S)
{
    while (S.top != S.base)
    {
        printf("%d ", *--S.top);
    }
    printf("\n");
    return 0;
}

int Stack_Empty(SqStack S)
{
    if (S.top == S.base)
        return 1;
    else
        return 0;
}

int Matching(SqStack& S, char* str)
{
    int n;
    n = strlen(str);
    if ((n % 2 )!= 0)  //为奇数括号时
        return 0;
    for (int i = 0; i < n; i++)
    {
        char ch;
        if ((str[i] == '(') || (str[i] == '[') || (str[i] == '{'))
            Stack_Push(S, str[i]);
        else if(str[i] == ')')
        {
            if ((S.top == S.base))
                return 0;
            else if (*--S.top != '(')
                return 0;
            else
                Stack_Pop(S, ch);
        }
        else if (str[i] == ']')
        {
            if ((S.top == S.base))
                return 0;
            else if (*--S.top != '[')
                return 0;
            else
                Stack_Pop(S, ch);
        }
        else if (str[i] == '}')
        {
            if ((S.top == S.base))
                return 0;
            else if (*--S.top != '{')
                return 0;
            else
                Stack_Pop(S, ch);
        }
    }
    return 1;
}

