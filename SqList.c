#include <stdio.h>
#include <stdlib.h>

#define LIST_INIT_SIZE 80  //线性表存储空间的初始分配量
#define LISTINCREMENT  10  //线性表存储空间的分配增量
#define ElemType  int  //数据元素类型
#define Status  bool  
#define OK  1
#define False 0

typedef struct {
	ElemType* elem;  //线性表基地址
	int length;      //当前长度
	int listszie;     //当前分配的存储容量
}SqList;



Status InitList_Sq(SqList &L)  //初始化顺序表
{
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	L.length = 0;
	L.listszie = LIST_INIT_SIZE;
	printf("顺序表初始化成功！\n");
	return OK;
}

Status CreateList_Sq(SqList& L)   //创建一个顺序表
{
	int a, i = 0;
	printf("创建一个顺序表，输入整型数据，以-1结束\n");
	scanf("%d", &a);
	while (a != -1)
	{
		if (L.length == L.listszie)
		{
			printf("顺序表已满\n");
			return false;
		}
		L.elem[i] = a;
		L.length++;
		i++;
		scanf("%d", &a);
	}
	printf("顺序表创建成功！\n");
	return OK;
}

Status InsertList_Sq(SqList& L, int i, ElemType e)  //在顺序表的第i个元素之前插入新的元素e
{
	if (L.length == L.listszie)
	{
		printf("顺序表已满\n");
		return false;
	}
	ElemType* p, *q;
	q = &L.elem[i - 1];
	for (p = &L.elem[L.length - 1]; p >= q; p--)
	{
		*(p + 1) = *p;
	}
	*q = e;
	L.length++;
	return OK;
}

Status DeleList_Sq(SqList& L, int i, ElemType &e)  //删除顺序表中的第i个元素
{
	ElemType* p, * q;
	q = &L.elem[i - 1];
	e = *q;
	for (int j = i; j <= L.length - 1; j++)
	{
		L.elem[j-1] = L.elem[j];
	}
	L.length--;
	return OK;
}

Status LocateList_Sq(SqList L, ElemType e)  //查找满足条件的第一个元素所在顺序表中的位置，存在的话则返回位序，否则返回0
{
	int i = 0;
	while (L.elem[i])
	{
		if (L.elem[i] == e)
			return i;
		i++;
	}
	return false;
}

Status PrintfList_Sq(SqList L)
{
	int i = 0;
	printf("顺序表打印如下：\n");
	while (i <= L.length - 1)
	{
		printf("%d\n", L.elem[i]);
		i++;
	}
	return OK;
}


int main()
{
	SqList L;
	InitList_Sq(L);
	CreateList_Sq(L);

	int n;
	while (1)
	{
		printf("请选择你想要进行的操作：\n  1.插入元素\n  2.删除元素\n  3.查找元素\n  4.打印顺序表\n  5.退出\n");
		scanf("%d", &n);
		switch (n)
		{
		case 1: 
		{
			int i, e;
			printf("请输入要插入的位置和元素：\n");
			scanf("%d%d", &i, &e);
			InsertList_Sq(L, i, e);
		};
			break;

		case 2:
		{
			int i,e;
			printf("请输入要删除的元素位置：\n");
			scanf("%d", &i);
			DeleList_Sq(L, i, e);
		}
			break;
		case 3: 
		{
			ElemType e;
			printf("请输入要查找的元素：\n");
			scanf("%d", &e);
			LocateList_Sq(L, e);
		}
			break;
		case 4: PrintfList_Sq(L); break;
		case 5: free(L.elem); return 0; break;
		}
	}
	
}
