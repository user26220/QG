#include <stdio.h>
#include "linkedList.h"
#include <stdlib.h>
//��ʼ������
Status InitList(LinkedList* L)
{
	//����ͷ���
	*L = (LinkedList)malloc(sizeof(LNode));
	(*L)->next = NULL;
}

//��p�ڵ�֮�����һ���ڵ�q
Status InsertList(LNode* p, LNode* q)
{
	//���в������
	q->next = p->next;
	p->next = q;
	return SUCCESS;
}

//ɾ��p֮��ĵ�һ���ڵ㣬���ҽ�p��ֵ����e
Status DeleteList(LNode* p, ElemType* e)
{
	//qΪp����һ���ڵ㣬����ɾ���Ľڵ�
	LNode* q;
	q = p->next;

	if (p->next == NULL)
		return ERROR;

	//p���ӵ���ɾ���ڵ����һ���ڵ�
	p->next = q->next;
	*e = q->data;

	free(q);
	return SUCCESS;
}

//������������չʾÿ���ڵ��ֵ
void TraverseList(LinkedList L, void (*visit)(ElemType e))
{
	//����Ϊ�գ�����
	if (IsLoopList(L))
	{
		printf("ERROR\n");
		return ERROR;
	}

	//pΪͷ�ڵ����һ���ڵ�
	LNode* p = L->next;
	//���д�ӡ
	while (p)
	{
		(*visit)(p->data);
		p = p->next;
	}
}

//�ҵ���һ����ֵe��ȵĽڵ�
Status SearchList(LinkedList L, ElemType e)
{
	//����Ϊ�գ�����
	if (IsLoopList(L))
	{
		printf("ERROR\n");
		return ERROR;
	}
		
	//num������book�ж������ҵ�
	int num = 0,book=0;
	LNode* p = L->next;
	//���б���
	while (p)
	{
		num++;
		if (p->data == e)
		{
			printf("��%d���ڵ��������\n", num);
			book = 1;
			break;
		}
		p = p->next;
	}
	if (book == 0)
		printf("û�ҵ�\n");

	return SUCCESS;
}

//��ת����
Status ReverseList(LinkedList* L)
{
	if (IsLoopList(*L))
	{
		printf("ERROR\n");
		return SUCCESS;
	}
	//��p��q��ָ���һ���ڵ�
	LNode* p = (*L)->next;
	LNode* q = p;

	//ɾ��ͷ���
	free(*L);
	*L = NULL;

	//���ڵ�p����ʱ
	while (p)
	{
		//����q�ߵ���һ���ڵ�
		q = q->next;

		//p����һ���ڵ�ָ��*L�������з�ת����
		p->next = *L;

		//*L����ס��ǰp��λ��
		*L = p;

		//p�ߵ���һ���ڵ㣬��q��λ��
		p = q;

	}

	//���´���ͷ���
	p = (LNode*)malloc(sizeof(LNode));
	p->next = *L;
	*L = p;


	return SUCCESS;
}

//�ж������Ƿ�Ϊ��
Status IsLoopList(LinkedList L)
{
	//ͷ���֮��Ϊ�գ�����true
	if (L->next == NULL)
		return SUCCESS;
	else
		return ERROR;
}

//������ż�ڵ�Ե�
LNode* ReverseEvenList(LinkedList* L)
{
	if (IsLoopList(*L))
	{
		printf("ERROR\n");
		return NULL;
	}

	if ((*L)->next==NULL)
	{
		printf("ֻ��һ����������\n");
		return NULL;
	}

	LNode* odd= (*L)->next;
	LNode* even=(*L)->next;
	LNode* p=even;	//����ָ��
	LNode* temp=*L;

	int ret = 0, swap = 0;			//������
	while (p)
	{
		ret++;
		if (ret % 2 == 0)	//�����ż��
		{
				//��ָ���ƶ�����Ӧλ��
				even = p;

				//��һ�ν���,temp������ͷ���
				if (ret / 2 == 1)
				{
					temp = *L;
				}
				//����temp��odd�ƶ�����Ӧλ��
				else
				{
					temp = odd;
					odd = odd->next;
				}
				

				p = p->next;
				//������ż�ڵ�
				even->next = odd;
				odd->next = even;
				//���½�������
				temp->next = even;
				odd->next = p;												
			
		}
		else
			//����ż��ҲҪ��ǰ��һ��
			p = p->next;
		
	}
	return NULL;

}

//�ҵ��м�ڵ�
LNode* FindMidNode(LinkedList* L)
{
	if (IsLoopList(*L))
	{
		printf("ERROR\n");
		return SUCCESS;
	}

	int num = 0;

	//ʹ�ÿ���ָ�뷨
	LNode* p = *L;
	LNode* q = p;

	while (q)
	{
		//p����һ����Ȼ��q��������
		p = p->next;
		num++;

		q = q->next;
		if (q == NULL)
		{
			printf("�м�ڵ�Ϊ%d����ֵΪ%d��", num, p->data);
			break;
		}
		//q��������һ��
		q = q->next;
		if (q == NULL)
		{
			printf("�м�ڵ�Ϊ%d����ֵΪ%d��", num, p->data);
			break;
		}

	}
	return SUCCESS;
}

//�������
void DestroyList(LinkedList* L)
{
	LNode* p;
	p=(*L)->next;

	//�ͷ�ͷ���
	free(*L);

	while (p)
	{
		*L = p->next;
		free(p);
		p = *L;
	}
}