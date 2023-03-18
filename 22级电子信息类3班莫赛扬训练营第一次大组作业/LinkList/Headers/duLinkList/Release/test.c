#include "dulLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
void Menu();
void ShowElem(ElemType e);
Status IsLoopList(DuLinkedList* L);
void InsertAfterList(DuLinkedList* L, int n);
void InsertBeforeList(DuLinkedList* L, int n);
void DeleteList(DuLinkedList* L, int n);
Status AddItem(ElemType e, DuLinkedList* L);
static void CopyToNode(ElemType e, DuLNode* pnode);
unsigned int ListElemCount(DuLinkedList* L);
Status HasCircle(DuLinkedList* L);
int main()
{
	//以下为Input.
	DuLinkedList list;
	ElemType temp = 0;
	InitList_DuL(&list);
	puts("请输入第一个数据(输入-1停止)：");
	while (scanf_s("%d", &temp) && temp != -1)
	{
		if (AddItem(temp, &list) == ERROR)
		{
			fprintf(stderr, "Problem allocating memory\n");
			break;
		}
		puts("输入下一个数据：");
	}
	int count = ListElemCount(&list);
	if (IsLoopList(&list))
		printf("\nNo data entered.\n");
	else
	{
		printf("你输入了%d个数据\n", count);
	}
	system("pause");
	system("cls");
	int type = 0, n = 0, num = 0;
	Menu();
	while (1)
	{
		type = getchar();
		switch (type)
		{
		case 'a':
			puts("请选择你操作的位置：");
			scanf_s("%d", &n);
			InsertBeforeList(&list, n);
			puts("已完成");
			printf("\n****************************\n");
			printf("请选择你的功能：");
			break;
		case 'b':
			puts("请选择你操作的位置：");
			scanf_s("%d", &n);
			InsertAfterList(&list,n);
			printf("\n****************************\n");
			printf("请选择你的功能：");
			break;
		case 'c':
			puts("请选择你删除的位置：");
			scanf_s("%d", &n);
			DeleteList(&list,n);
			printf("\n****************************\n");
			printf("请选择你的功能：");
			break;
		case 'd':
			TraverseList_DuL(list, ShowElem);
			puts("已完成");
			printf("\n****************************\n");
			printf("请选择你的功能：");
			break;
		case 'e':
			if (HasCircle(&list))
				printf("成环");
			else
				printf("不成环");			
			printf("\n****************************\n");
			printf("请选择你的功能：");
			break;
		case 'f':
			DestroyList_DuL(&list);
			printf("\nBye!");
			exit(1);
			break;
		}
	}
	return 0;
}

void Menu()
{
	for (int i = 0; i < 70; i++)
		printf("*");
	printf("\n");
	for (int i = 0; i < 5; i++)
		puts("*\t\t\t\t\t\t\t\t\t");
	puts("*\t		||  a.插入到结点	之前		||\t\t\t\n");
	puts("*\t		||  b.插入到结点之后		||\t\t\t\n");
	puts("*\t		||  c.删除结点			||\t\t\t\n");
	puts("*\t		||  d.遍历				||\t\t\t\n");
	puts("*\t		||  e.判断成环				||\t\t\t\n");
	puts("*\t		||  f.退出程序			||\t\t\t\n");
	printf("\n\n\n");
	for (int i = 0; i < 70; i++)
		printf("*");
	printf("\n");
	printf("请选择你的功能：");

}

void ShowElem(ElemType e)
{
	printf("%d \n", e);
}

