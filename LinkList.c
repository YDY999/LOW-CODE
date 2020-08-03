#include<stdio.h>
#include<stdlib.h>
#define OK 1
typedef int ElemType;


typedef struct LNode {
	ElemType Data;
	struct LNode* Next;
}LNode, * LinkList;

int CreateList_T(LinkList& L, int n)  //（尾插法建表）顺序输入n个元素，创建带头结点的单链表
{
	L = (LinkList)malloc(sizeof(LNode));
	L->Next = NULL;
	LNode* p, * q=L;
	ElemType e;
	for (int i = 1; i <= n; i++)
	{
		p = (LNode*)malloc(sizeof(LNode));
		scanf("%d", &e);
		p->Data = e;
		p->Next = q->Next;
		q->Next = p;
		q = p;
	}
	q->Next = NULL;
	return OK;
}

int CreateList_H(LinkList& L, int n)  //（头插法）逆序输入n个元素，创建带头结点的单链表
{
	L = (LinkList)malloc(sizeof(LNode));
	L->Next = NULL;
	LNode* p;
	ElemType e;
	for (int i = 1; i <= n; i++)
	{
		p = (LNode*)malloc(sizeof(LNode));
		scanf("%d", &e);
		p->Data = e;
		p->Next = L->Next;
		L->Next = p;
	}
	return OK;
}

int ListInsert(LinkList& L, int i, ElemType e)  //在单链表的第i个元素前插入元素e
{
	LNode* p = L, * q;
	for (int j = 1; j < i; j++)
	{
		p = p->Next;
	}
	q = (LNode*)malloc(sizeof(LNode));
	q->Data = e;
	q->Next = p->Next;
	p->Next = q;
	return OK;
}

int ListDele(LinkList& L, int i, ElemType& e)  //删除单链表中的第i个元素
{
	LNode* p = L, * q;
	for (int j = 1; j < i; j++)
	{
		p = p->Next;
	}
	q = p->Next;
	e = q->Data;
	p->Next = q->Next;
	free(q);
	return OK;
}

int ListPrintf(LinkList L)  //打印单链表中的元素
{
	L = L->Next;
	while (L)
	{
		printf("%d ", L->Data);
		L = L->Next;
	}
	printf("\n");
	return OK;
}

int main()
{
	LinkList L;
	int n;
	printf("请输入单链表中的元素个数：");
	scanf("%d", &n);
	CreateList_T(L,n);
	while (1)
	{
		printf("请选择想要进行的操作：\n  1.插入元素\n  2.删除元素\n  3.打印链表\n  其它则退出\n");
		int i;
		scanf("%d", &i);
		switch (i)
		{
		  case 1:
		  {
			  int e, j; 
			  printf("请输入要插入的元素及相应的插入位置（以" "隔开）："); 
			  scanf("%d %d", &e, &j); 
			  ListInsert(L, j, e);
			  break;
		  }
		  case 2:
		  {
			  int e, j;
			  printf("请输入要删除的元素位置：");
			  scanf("%d", &j);
			  ListDele(L, j, e);
			  break;
		  }
		  case 3:ListPrintf(L); break;
		  default:return 0; break;
		}
	}
	return 0;
}
