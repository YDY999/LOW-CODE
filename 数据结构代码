#include <stdio.h>
#include<stdlib.h>
#define OK 1
#define FALSE 0

typedef int SElemType;


typedef struct SNode {
	SElemType date;  //节点数据域
	struct SNode* next;  //节点指针域
}SNode,* LinkStack;

int InitStack(LinkStack& Top)
{
	Top = NULL;
	return OK;
}

int Push(LinkStack& Top, SElemType date)  //将数据元素压入栈中
{
	SNode* node;
	node = (SNode*)malloc(sizeof(SNode));
	node->date = date;
	node->next = Top;
	Top = node;
	return OK;
}

int Pop(LinkStack& Top, SElemType &e)  //弹出栈内元素
{
	SNode* p;
	if (Top == NULL)
	{
		printf("栈空\n");
		return FALSE;
	}
	e = Top->date;
	p = Top;
	Top = Top->next;
	free(p);
	return OK;
}

int Print(LinkStack Top)  //打印栈内元素
{
	printf("栈内的元素为：");
	while (Top)
	{
		printf("%d ", Top->date);
		Top = Top->next;
	}
	printf("\n");
	return OK;
}

int main()
{
	LinkStack Top;
	InitStack(Top);
	while (1)
	{
		int n;
		printf("请根据序号选择相应的操作：\n  1.将元素压入栈中\n  2.将元素弹出栈\n  3.打印栈内元素\n  否则按其它键退出\n");
		scanf("%d", &n);
		switch (n)
		{
		    case 1:
			{
				int date;
				printf("请输入元素：");
				scanf("%d", &date);
				Push(Top, date);
				break;
			}
			case 2:
			{
				SElemType date;
				Pop(Top, date);
				printf("弹出栈内元素：%d\n", date);
				break;
			}
			case 3:Print(Top); break;
			default:return 0;
		}
	}
}
