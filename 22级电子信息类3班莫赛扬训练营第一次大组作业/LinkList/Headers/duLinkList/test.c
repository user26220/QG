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
	//����ΪInput.
	DuLinkedList list;
	ElemType temp = 0;
	InitList_DuL(&list);
	puts("�������һ������(����-1ֹͣ)��");
	while (scanf_s("%d", &temp) && temp != -1)
	{
		if (AddItem(temp, &list) == ERROR)
		{
			fprintf(stderr, "Problem allocating memory\n");
			break;
		}
		puts("������һ�����ݣ�");
	}
	int count = ListElemCount(&list);
	if (IsLoopList(&list))
		printf("\nNo data entered.\n");
	else
	{
		printf("��������%d������\n", count);
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
			puts("��ѡ���������λ�ã�");
			scanf_s("%d", &n);
			InsertBeforeList(&list, n);
			puts("�����");
			printf("\n****************************\n");
			printf("��ѡ����Ĺ��ܣ�");
			break;
		case 'b':
			puts("��ѡ���������λ�ã�");
			scanf_s("%d", &n);
			InsertAfterList(&list,n);
			printf("\n****************************\n");
			printf("��ѡ����Ĺ��ܣ�");
			break;
		case 'c':
			puts("��ѡ����ɾ����λ�ã�");
			scanf_s("%d", &n);
			DeleteList(&list,n);
			printf("\n****************************\n");
			printf("��ѡ����Ĺ��ܣ�");
			break;
		case 'd':
			TraverseList_DuL(list, ShowElem);
			puts("�����");
			printf("\n****************************\n");
			printf("��ѡ����Ĺ��ܣ�");
			break;
		case 'e':
			if (HasCircle(&list))
				printf("�ɻ�");
			else
				printf("���ɻ�");			
			printf("\n****************************\n");
			printf("��ѡ����Ĺ��ܣ�");
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
	puts("*\t		||  a.���뵽���	֮ǰ		||\t\t\t\n");
	puts("*\t		||  b.���뵽���֮��		||\t\t\t\n");
	puts("*\t		||  c.ɾ�����			||\t\t\t\n");
	puts("*\t		||  d.����				||\t\t\t\n");
	puts("*\t		||  e.�жϳɻ�				||\t\t\t\n");
	puts("*\t		||  f.�˳�����			||\t\t\t\n");
	printf("\n\n\n");
	for (int i = 0; i < 70; i++)
		printf("*");
	printf("\n");
	printf("��ѡ����Ĺ��ܣ�");

}

void ShowElem(ElemType e)
{
	printf("%d \n", e);
}

