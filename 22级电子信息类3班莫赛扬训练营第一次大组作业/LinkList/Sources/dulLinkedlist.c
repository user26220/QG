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
	p->prior->next = q;			/*����p֮ǰ�Ľ��*/
	q->prior = p->prior;			
	q->next = p;				/*����p���*/
	p->prior = q;
	return SUCCESS;
}

Status InsertAfterList_DuL(DuLNode* p, DuLNode* q)
{
	p->next->prior = q;			/*����p֮��Ľ��*/
	q->next = p->next;
	q->prior = p;				/*����p���*/
	p->next = q;
	return SUCCESS;
}

Status DeleteList_DuL(DuLNode* p, ElemType* e)
{
	p->next->prior = p->prior;	//p֮��Ľ������p֮ǰ�Ľ����
	p->prior->next = p->next;	//p֮ǰ�Ľ������p֮��Ľ����
	*e = p->data;				//���ر�ɾ����ֵ
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
		printf("��%d������:", count);
		(*visit)(pnode->data);
		pnode = pnode->next;
	}
	if (count == 0)
		printf("û�ñ�����\n");
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
	puts("��������������:");
	pnew->next = NULL;
	pnew->prior = NULL;
	scanf_s("%d", &pnew->data);
	if (IsLoopList(L))
	{
		*L = pnew;
	}							//���Ϊ�գ�ֱ�ӷ���*L��
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
	puts("��������������:");
	pnew->next = NULL;
	pnew->prior = NULL;
	scanf_s("%d", &pnew->data);
	if (IsLoopList(L))
		*L = pnew;						//���Ϊ�գ�ֱ�ӷ���*L��
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
		printf("ERROR\n");						//���Ϊ�գ�ֱ�ӷ���*L��
	else
	{
		for (p = *L; p; p = p->next)
		{
			if (++count == n)
			{
				DeleteList_DuL(p, &e);
				printf("��ɾ���˵�%d�����ݣ�%d",count,e);
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
