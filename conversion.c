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
		printf("请根据序号选择相应的进制转换：\n  1.转换成2进制\n  2.转换成8进制\n  3.转换成16进制\n 否则按其它键退出\n");
		scanf("%d", &n);
		switch (n)
		{
		    case 1:
			{
				int date;
				printf("请输入10进制数据：");
				scanf("%d", &date);
				while (date)
				{
					Push(Top, date%2);
					date /= 2;
				}
				printf("转换成2进制数为：");
				while (Top)
				{
					Pop(Top, date);
					printf("%d ", date);
				}
				printf("\n");
				break;
			}
			case 2:
			{
				int date;
				printf("请输入10进制数据：");
				scanf("%d", &date);
				while (date)
				{
					Push(Top, date % 8);
					date /= 8;
				}
				printf("转换成8进制数为：");
				while (Top)
				{
					Pop(Top, date);
					printf("%d ", date);
				}
				printf("\n");
				break;
			}
			case 3:
			{
				int date;
				printf("请输入10进制数据：");
				scanf("%d", &date);
				while (date)
				{
					Push(Top, date % 16);
					date /= 16;
				}
				printf("转换成16进制数为：");
				while (Top)
				{
					Pop(Top, date);
					printf("%d ", date);
				}
				printf("\n");
				break;
			}
			default:return 0;
		}
	}
}
