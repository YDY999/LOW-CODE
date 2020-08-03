#include<stdio.h>
#include<stdlib.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT  10
#define OK 1
#define FALSE 0
typedef int SElemType;

typedef struct {
	SElemType* base;
	SElemType* top;  //指向栈顶的下一元素
	int stacksize;
}Sqstack;

int InitStack(Sqstack &S)  //初始化一个空栈S
{
	S.base = (SElemType*)malloc(sizeof(SElemType) * STACK_INIT_SIZE);
	S.stacksize = STACK_INIT_SIZE;
	S.top = S.base;
	return OK;
}

int Push(Sqstack &S, SElemType e)  //往栈里边压入元素e
{
	if (S.top - S.base >= S.stacksize)  //栈满，追加存储空间
	{
		S.base = (SElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;  //先赋值，后栈顶指针加1
	return OK;
}

int Pop(Sqstack &S, SElemType &e)  //栈内弹出的元素赋值给e
{
	if (S.top == S.base)  //栈空
		return FALSE;
	e = *S.top--;
	return OK;
}

int Print(Sqstack S)  //打印栈内元素
{
	printf("栈内元素为：\n");
	while (S.top != S.base)
	{
		printf("%d ", *S.base++);
	}
	printf("\n");
	return OK;
}

int main()
{
	Sqstack S;
	InitStack(S);
	int n;
	while (1)
	{
		printf("请选择想要的操作：\n  1.入栈\n  2.出栈\n  3.打印栈内元素\n  其它则退出\n");
		scanf("%d", &n);
		switch (n)
		{
		  case 1:
		  {
			  SElemType e;
			  printf("输入入栈元素：");
			  scanf("%d", &e);
			  Push(S, e);
			  break;
		  }
		  case 2:
		  {
			  SElemType e;
			  Pop(S, e);
			  printf("出栈的栈元素为：\n");
			  break;
		  }
		  case 3: Print(S); break;
		  default:return 0; break;
		}
	}
}

