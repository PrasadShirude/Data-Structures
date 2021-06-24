// Insert at first node

#include<stdio.h>
#include<stdlib.h>

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

struct node
{
	int data;
	struct node *next;
};

void InsertFirst(PPNODE Head, int No)
{	
	PNODE newn = NULL;

	newn = (PNODE)malloc(sizeof(NODE));
	newn->data = No;
	newn->next = NULL;

	if(*Head == NULL) 		// LL is empty
	{
		*Head = newn;
	}
	else					// LL has atleast one node
	{
		newn->next = *Head;
		*Head = newn;
	}

}

void Display(PNODE Head)
{	
	int iCnt = 0;
	while(Head != NULL)
	{
		printf("%d\n",Head->data);
		iCnt++;
		Head = Head->next;
	}
	printf("No.of nodes are : %d\n",iCnt);
}
int main()
{
	PNODE First = NULL;		// struct node *First = NULL
	
	InsertFirst(&First,51);
	InsertFirst(&First,21);
	InsertFirst(&First,11);
	
	Display(First);

	return 0;
}