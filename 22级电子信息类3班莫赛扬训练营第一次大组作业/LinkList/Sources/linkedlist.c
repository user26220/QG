#include <stdio.h>
#include "linkedList.h"
#include <stdlib.h>
//初始化链表
Status InitList(LinkedList* L)
{
	//创建头结点
	*L = (LinkedList)malloc(sizeof(LNode));
	(*L)->next = NULL;
}

//在p节点之后插入一个节点q
Status InsertList(LNode* p, LNode* q)
{
	//进行插入操作
	q->next = p->next;
	p->next = q;
	return SUCCESS;
}

//删除p之后的第一个节点，并且将p的值赋给e
Status DeleteList(LNode* p, ElemType* e)
{
	//q为p的下一个节点，即被删除的节点
	LNode* q;
	q = p->next;

	if (p->next == NULL)
		return ERROR;

	//p链接到被删除节点的下一个节点
	p->next = q->next;
	*e = q->data;

	free(q);
	return SUCCESS;
}

//遍历链表，并且展示每个节点的值
void TraverseList(LinkedList L, void (*visit)(ElemType e))
{
	//链表为空，返回
	if (IsLoopList(L))
	{
		printf("ERROR\n");
		return ERROR;
	}

	//p为头节点的下一个节点
	LNode* p = L->next;
	//进行打印
	while (p)
	{
		(*visit)(p->data);
		p = p->next;
	}
}

//找到第一个和值e相等的节点
Status SearchList(LinkedList L, ElemType e)
{
	//链表为空，返回
	if (IsLoopList(L))
	{
		printf("ERROR\n");
		return ERROR;
	}
		
	//num计数，book判断有无找到
	int num = 0,book=0;
	LNode* p = L->next;
	//进行遍历
	while (p)
	{
		num++;
		if (p->data == e)
		{
			printf("第%d个节点符合条件\n", num);
			book = 1;
			break;
		}
		p = p->next;
	}
	if (book == 0)
		printf("没找到\n");

	return SUCCESS;
}

//反转链表
Status ReverseList(LinkedList* L)
{
	if (IsLoopList(*L))
	{
		printf("ERROR\n");
		return SUCCESS;
	}
	//让p，q都指向第一个节点
	LNode* p = (*L)->next;
	LNode* q = p;

	//删除头结点
	free(*L);
	*L = NULL;

	//当节点p存在时
	while (p)
	{
		//首先q走到下一个节点
		q = q->next;

		//p的下一个节点指向*L，即进行反转操作
		p->next = *L;

		//*L保存住当前p的位置
		*L = p;

		//p走到下一个节点，即q的位置
		p = q;

	}

	//重新创立头结点
	p = (LNode*)malloc(sizeof(LNode));
	p->next = *L;
	*L = p;


	return SUCCESS;
}

//判断链表是否为空
Status IsLoopList(LinkedList L)
{
	//头结点之后为空，返回true
	if (L->next == NULL)
		return SUCCESS;
	else
		return ERROR;
}

//链表奇偶节点对调
LNode* ReverseEvenList(LinkedList* L)
{
	if (IsLoopList(*L))
	{
		printf("ERROR\n");
		return NULL;
	}

	if ((*L)->next==NULL)
	{
		printf("只有一个，换不了\n");
		return NULL;
	}

	LNode* odd= (*L)->next;
	LNode* even=(*L)->next;
	LNode* p=even;	//遍历指针
	LNode* temp=*L;

	int ret = 0, swap = 0;			//计数君
	while (p)
	{
		ret++;
		if (ret % 2 == 0)	//如果是偶数
		{
				//将指针移动到相应位置
				even = p;

				//第一次交换,temp保持在头结点
				if (ret / 2 == 1)
				{
					temp = *L;
				}
				//否则temp和odd移动到相应位置
				else
				{
					temp = odd;
					odd = odd->next;
				}
				

				p = p->next;
				//交换奇偶节点
				even->next = odd;
				odd->next = even;
				//重新将线连上
				temp->next = even;
				odd->next = p;												
			
		}
		else
			//不是偶数也要往前走一步
			p = p->next;
		
	}
	return NULL;

}

//找到中间节点
LNode* FindMidNode(LinkedList* L)
{
	if (IsLoopList(*L))
	{
		printf("ERROR\n");
		return SUCCESS;
	}

	int num = 0;

	//使用快慢指针法
	LNode* p = *L;
	LNode* q = p;

	while (q)
	{
		//p先走一步，然后q连走两步
		p = p->next;
		num++;

		q = q->next;
		if (q == NULL)
		{
			printf("中间节点为%d，数值为%d：", num, p->data);
			break;
		}
		//q再往后走一步
		q = q->next;
		if (q == NULL)
		{
			printf("中间节点为%d，数值为%d：", num, p->data);
			break;
		}

	}
	return SUCCESS;
}

//清空链表
void DestroyList(LinkedList* L)
{
	LNode* p;
	p=(*L)->next;

	//释放头结点
	free(*L);

	while (p)
	{
		*L = p->next;
		free(p);
		p = *L;
	}
}