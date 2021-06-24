// Insert at last node

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

void InsertLast(PPNODE Head, int No)
{	
	PNODE newn = NULL;
	PNODE temp = *Head;

	newn = (PPNODE)malloc(sizeof(NODE));
	newn->data = No;
	newn->next = NULL;

	if(*Head == NULL) 		// LL is empty
	{
		*Head = newn;
	}
	else					// LL has atleast one node
	{
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newn;
	}

}

void DeleteFirst(PPNODE Head)
{	
	PNODE temp = *Head;

	if(*Head == NULL)	//LL is empty
	{
		return;
	}
	else if((*Head)->next == NULL)	//LL has one node
	{
		free(*Head);	// Delete that first node
		*Head = NULL;	// set NULL to first pointer
	}
	else							// LL has more than one node
	{
		(*Head) = (*Head) -> next;
		free(temp);
	}
}

void DeleteLast(PPNODE Head)
{	
	PNODE temp = *Head;

	if(*Head == NULL)	//LL is empty
	{
		return;
	}
	else if((*Head)->next == NULL)	// LL has one node
	{
		free(*Head);		// Delete that first node
		*Head = NULL;		// set NULL to first pointer
	}
	else							// LL has more than one node
	{
		while(temp->next->next != NULL)
		{
			temp = temp->next;
		}
		free(temp->next);
		temp->next = NULL;
	}
}

void Display(PNODE Head)
{	

	while(Head != NULL)
	{
		printf("|%d|\t",Head->data);
		
		Head = Head->next;
	}
	//printf("No.of nodes are : %d\n",iCnt);
}


int main()
{
	PNODE First = NULL;		// struct node *First = NULL
	
	InsertLast(&First,11);
	InsertLast(&First,21);
	InsertLast(&First,51);
	printf("Nodes \n");
	Display(First);

	DeleteFirst(&First);
	
	printf("\nlinked list after delete first\n");
	Display(First);

	DeleteLast(&First);
	printf("\nlinked list after delete last\n");
	Display(First);

	return 0;
}