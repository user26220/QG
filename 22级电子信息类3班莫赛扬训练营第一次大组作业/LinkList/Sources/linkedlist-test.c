#include<stdio.h>
#include "linkedlist.h"
#include <time.h>
#include<string.h>
#include <stdlib.h>

int num = 0;

void Menu();
void ShowElem(ElemType e);
Status InsertLink(LinkedList* L, int n);
Status AddItem(LinkedList* L, int ref);
Status DeleteLink(LinkedList* L, int n);

int main()
{
	//��������
	LinkedList list;
	InitList(&list);

	int type = 0, n = 0, num = 0;
	//��������
	printf("�����봴������\n");
	printf("��1�ֶ�����\n��2�Զ�����(10���ڵ�����)\n");
	printf("���������ѡ��");
	scanf_s("%d", &num);
	AddItem(&list, num);
	
	system("pause");
	system("cls");


	/*����Ϊ�˵�չʾ�빦��ѡ��*/
	Menu();
	while (1)
	{
		printf("��ѡ����Ĺ��ܣ�");
		scanf_s("%d", &type);		

		switch (type)
		{
			fflush(stdin);
		case 1:			
			puts("��ѡ��������λ�ã�");
			scanf_s("%d", &n);
			if(InsertLink(&list, n))				
				puts("�����");
			else
				puts("ERROR");
			printf("\n****************************\n");
			break;
		case 2:
			puts("��ѡ����ɾ����λ�ã�");
			scanf_s("%d", &n);
			if (DeleteLink(&list, n))
				puts("�����");
			else
				puts("ERROR");
			printf("\n****************************\n");
			break;
		case 3:
			puts("����������Ҫ���������ݣ�");
			scanf_s("%d", &n);
			SearchList(list, n);
			printf("\n****************************\n");
			break;
		case 4:
			ReverseList(&list);
			puts("�����");
			printf("\n****************************\n");
		case 5:
			TraverseList(list, ShowElem);
			puts("�����");
			printf("\n****************************\n");
			break;
		case 6:
			FindMidNode(&list);
			printf("\n****************************\n");
			break;
		case 7:
			ReverseEvenList(&list);
			printf("�𾪣��㷴ת��������ż�����\n");
			printf("\n****************************\n");
			break;
		case 8:
			system("cls");
			Menu();
			printf("\n****************************\n");
			break;
		case 9:
			DestroyList(&list);
			printf("\nBye!");
			exit(1);
			break;
		}

		
	}
	return 0;
}


void ShowElem(ElemType e)
{
	printf("%d \n", e);
}

void Menu()
{
	for (int i = 0; i < 70; i++)
		printf("*");
	for (int i = 0; i < 5; i++)
		puts("*\t\t\t\t\t\t\t\t\t");
	puts("*\t		||  1.��ӽڵ�		||\t\t\t\n");
	puts("*\t		||  2.ɾ�����		||\t\t\t\n");
	puts("*\t		||  3.�������		||\t\t\t\n");
	puts("*\t		||  4.��ת����(�ǵݹ�)		||\t\t\t\n");
	puts("*\t		||  5.��������		||\t\t\t\n");
	puts("*\t		||  6.���е�		||\t\t\t\n");
	puts("*\t		||  7.��ת��ż		||\t\t\t\n");
	puts("*\t		||  8.ˢ�½���		||\t\t\t\n");
	puts("*\t		||  9.�˳�����		||\t\t\t\n");
	for (int i = 0; i < 70; i++)
		printf("*");
	printf("\n");

}

Status AddItem(LinkedList* L,int ref)
{
	ElemType temp;
	LNode* q= *L;

	srand((unsigned)time(NULL));
	if (ref == 1)
	{
		puts("�������һ������(����-1ֹͣ)��");

		while (scanf_s("%d", &temp) && temp != -1)
		{
			LNode* p = (LNode*)malloc(sizeof(LNode));
			if (p == NULL)
				return ERROR;
			p->next = NULL;
			p->data = temp;

			q->next = p;
			q = p;

			num++;

			puts("������һ�����ݣ�");
		}

		if (IsLoopList(*L))
			printf("No data entered.\n");
		else
		{
			printf("��������%d������\n", num);
		}
	}
	
	if (ref == 2)
	{
		int count = 0;
		num = rand() % 10+1;


		while (count < num)
		{
			temp = rand() % 20 + 1;
			LNode* pnew;
			pnew = (LNode*)malloc(sizeof(LNode));
			if (pnew == NULL)
				return ERROR;
			pnew->next = NULL;
			pnew->data = temp;

			q->next = pnew;
			q = pnew;

			count++;
		}
		if (IsLoopList(*L))
			printf("No data entered.\n");
		else
		{
			printf("��������%d������\n", num);
		}
	}
	return SUCCESS;
}

Status InsertLink(LinkedList* L,int n)
{
	
	int count = 0,book=0;
	LNode* p = *L;

	//��ʼ��q
	LNode* q= (LNode*)malloc(sizeof(LNode));
	q->next = NULL;
	printf("������Ҫ����ڵ��ֵ:\n");
	scanf_s("%d", &q->data);

	while (p)
	{
		count++;
		if (count == n)
		{			
			InsertList(p, q);
			book = 1;
			break;
		}
		p = p->next;

	}
	if (book == 0)
	{
		printf("����λ����Ч\n");
	}
	return SUCCESS;
}

Status DeleteLink(LinkedList* L, int n)
{
	if (IsLoopList(*L) || n > num)
	{
		return ERROR;
	}

	LNode* p=*L;
	ElemType temp=0;
	int count = 0,book=0;

	while (p)
	{
		count++;
		if (count == n)
		{
			if(DeleteList(p, &temp))
			{
				printf("��ɾ�����ݣ�%d\n", temp);
				book = 1;
			}
			else
			{
				printf("�޷�ɾ����һ���ڵ�\n");
			}
			
			break;

		}	
		p = p->next;
	}

	if (book == 0)
	{
		printf("ɾ��λ����Ч\n");
	}
	return SUCCESS;
}