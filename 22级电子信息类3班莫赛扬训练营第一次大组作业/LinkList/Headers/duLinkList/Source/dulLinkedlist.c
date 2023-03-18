#include <stdio.h>
#include "dulLinkedList.h"
#include <stdlib.h>
Status IsLoopList(DuLinkedList* L);
void InsertAfterList(DuLinkedList* L, int n);
void InsertBeforeList(DuLinkedList* L, int n);
void DeleteList(DuLinkedList* L, int n);
Status AddItem(ElemType e, DuLinkedList* L);
static void CopyToNode(ElemType e, DuLNode* pnode);
unsigned int ListElemCount(DuLinkedList* L);
Status HasCircle(DuLinkedList* L);
Status InitList_DuL(DuLinkedList* L)
{
	*L = NULL;
	return SUCCESS;
}

void DestroyList_DuL(DuLinkedList* L)
{
	while (*L)										
	{
		if ((*L)->next == NULL)
		{
			free(*L);
			break;
		}
		*L = (*L)->next;
		free((*L)->prior);
	}
}

Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q)
{
	p->prior->next = q;			/*连接p之前的结点*/
	q->prior = p->prior;			
	q->next = p;				/*连接p结点*/
	p->prior = q;
	return SUCCESS;
}

Status InsertAfterList_DuL(DuLNode* p, DuLNode* q)
{
	p->next->prior = q;			/*连接p之后的结点*/
	q->next = p->next;
	q->prior = p;				/*连接p结点*/
	p->next = q;
	return SUCCESS;
}

Status DeleteList_DuL(DuLNode* p, ElemType* e)
{
	p->next->prior = p->prior;	//p之后的结点连到p之前的结点上
	p->prior->next = p->next;	//p之前的结点连到p之后的结点上
	*e = p->data;				//返回被删除的值
	free(p);
	return SUCCESS;
}

void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
{
	DuLNode* pnode = L;
	int count = 0;
	while (pnode)
	{
		count++;
		printf("第%d项数据:", count);
		(*visit)(pnode->data);
		pnode = pnode->next;
	}
	if (count == 0)
		printf("没得遍历了\n");
}
Status IsLoopList(DuLinkedList* L)
{
	if (*L == NULL)
		return SUCCESS;
	else
		return ERROR;
}
void InsertBeforeList(DuLinkedList* L, int n)
{
	int count = 0;
	DuLNode* p;
	DuLNode* pnew = (DuLNode*)malloc(sizeof(DuLNode));
	puts("请输入插入的数据:");
	pnew->next = NULL;
	pnew->prior = NULL;
	scanf_s("%d", &pnew->data);
	if (IsLoopList(L))
	{
		*L = pnew;
	}							//如果为空，直接放在*L处
	else
	{
		for (p = *L; p; p = p->next)
		{
			if (++count == n)
				if (n == 1)
				{
					pnew->next = p;
					p->prior = pnew;
					*L = pnew;
					break;
				}
				InsertBeforeList_DuL(p, pnew);
				
		}
	}
}

void InsertAfterList(DuLinkedList* L, int n)
{
	int count=0;
	DuLNode* p;
	DuLNode* pnew = (DuLNode*)malloc(sizeof(DuLNode));
	puts("请输入插入的数据:");
	pnew->next = NULL;
	pnew->prior = NULL;
	scanf_s("%d", &pnew->data);
	if (IsLoopList(L))
		*L = pnew;						//如果为空，直接放在*L处
	else
	{
		for (p = *L; p; p = p->next)
		{
			if (++count == n)
				InsertAfterList_DuL(p, pnew);
		}
	}


}

void DeleteList(DuLinkedList* L, int n)
{
	DuLNode* p = *L;
	ElemType e = 0;
	int count = 0;
	if (IsLoopList(L))
		printf("ERROR\n");						//如果为空，直接放在*L处
	else
	{
		for (p = *L; p; p = p->next)
		{
			if (++count == n)
			{
				DeleteList_DuL(p, &e);
				printf("你删除了第%d项数据：%d",count,e);
				break;
			}
			else
				printf("ERROR");
		}
	}
}

Status AddItem(ElemType e, DuLinkedList* L)
{
		DuLNode* pnew;
		DuLNode* scan = *L;
		pnew = (DuLNode*)malloc(sizeof(DuLNode));
		if (pnew == NULL)
			return ERROR;
		CopyToNode(e, pnew);
		pnew->next = NULL;
		pnew->prior = NULL;
		if (scan == NULL)
			*L = pnew;
		else
		{
			while (scan->next)
				scan = scan->next;
			scan->next = pnew;
			pnew->prior = scan;
		}
		return SUCCESS;
	
}
static void CopyToNode(ElemType e, DuLNode* pnode)
{
	pnode->data = e;
}

unsigned int ListElemCount(DuLinkedList* L)
{
	unsigned int count = 0;
	DuLNode* pnode = *L;
	if (pnode)
	{
		while (pnode)
		{
			count++;
			pnode = pnode->next;
		}
		return count;
	}
	else
	{
		printf("ERROR");
		return ERROR;
	}
}

Status HasCircle(DuLinkedList* L)
{
	if (IsLoopList(L))
		return ERROR;
	DuLNode* slow = *L;
	DuLNode* fast=*L;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return SUCCESS;
	}
	return ERROR;
}
