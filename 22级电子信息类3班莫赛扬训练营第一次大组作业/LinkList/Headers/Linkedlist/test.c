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
	//创建链表
	LinkedList list;
	InitList(&list);

	int type = 0, n = 0, num = 0;
	//生成链表
	printf("首先请创建链表：\n");
	printf("扣1手动输入\n扣2自动生成(10个节点以内)\n");
	printf("请输入你的选择：");
	scanf_s("%d", &num);
	AddItem(&list, num);
	
	system("pause");
	system("cls");


	/*以下为菜单展示与功能选择*/
	Menu();
	while (1)
	{
		printf("请选择你的功能：");
		scanf_s("%d", &type);		

		switch (type)
		{
			fflush(stdin);
		case 1:			
			puts("请选择你插入的位置：");
			scanf_s("%d", &n);
			if(InsertLink(&list, n))				
				puts("已完成");
			else
				puts("ERROR");
			printf("\n****************************\n");
			break;
		case 2:
			puts("请选择你删除的位置：");
			scanf_s("%d", &n);
			if (DeleteLink(&list, n))
				puts("已完成");
			else
				puts("ERROR");
			printf("\n****************************\n");
			break;
		case 3:
			puts("请输入你想要搜索的数据：");
			scanf_s("%d", &n);
			SearchList(list, n);
			printf("\n****************************\n");
			break;
		case 4:
			ReverseList(&list);
			puts("已完成");
			printf("\n****************************\n");
		case 5:
			TraverseList(list, ShowElem);
			puts("已完成");
			printf("\n****************************\n");
			break;
		case 6:
			FindMidNode(&list);
			printf("\n****************************\n");
			break;
		case 7:
			ReverseEvenList(&list);
			printf("震惊！你反转了奇数和偶数结点\n");
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
	puts("*\t		||  1.添加节点		||\t\t\t\n");
	puts("*\t		||  2.删除结点		||\t\t\t\n");
	puts("*\t		||  3.搜索结点		||\t\t\t\n");
	puts("*\t		||  4.反转链表(非递归)		||\t\t\t\n");
	puts("*\t		||  5.遍历链表		||\t\t\t\n");
	puts("*\t		||  6.找中点		||\t\t\t\n");
	puts("*\t		||  7.反转奇偶		||\t\t\t\n");
	puts("*\t		||  8.刷新界面		||\t\t\t\n");
	puts("*\t		||  9.退出程序		||\t\t\t\n");
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
		puts("请输入第一个数据(输入-1停止)：");

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

			puts("输入下一个数据：");
		}

		if (IsLoopList(*L))
			printf("No data entered.\n");
		else
		{
			printf("你输入了%d个数据\n", num);
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
			printf("你输入了%d个数据\n", num);
		}
	}
	return SUCCESS;
}

Status InsertLink(LinkedList* L,int n)
{
	
	int count = 0,book=0;
	LNode* p = *L;

	//初始化q
	LNode* q= (LNode*)malloc(sizeof(LNode));
	q->next = NULL;
	printf("请输入要插入节点的值:\n");
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
		printf("插入位置无效\n");
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
				printf("已删除数据：%d\n", temp);
				book = 1;
			}
			else
			{
				printf("无法删除下一个节点\n");
			}
			
			break;

		}	
		p = p->next;
	}

	if (book == 0)
	{
		printf("删除位置无效\n");
	}
	return SUCCESS;
}