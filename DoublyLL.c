#include<stdlib.h>
#include<stdio.h>


struct node 
{
	int data;
	struct node *next;
	struct node *prev;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;


int Count(PNODE Head)
{	
	int iCnt = 0;
	while(Head != NULL)
	{
		iCnt++;
		Head = Head->next;
	}

	return iCnt;
}
void InsertFirst(PPNODE Head,int iNo)
{
	PNODE newn = NULL;

	newn = (PNODE)malloc(sizeof(NODE));
	newn->data = iNo;
	newn->next = NULL;
	newn->prev = NULL;

	if(*Head == NULL)
	{
		*Head = newn;
	}
	else
	{
		newn->next = *Head;
		(*Head)->prev = newn;
		*Head = newn;
	}
}

void InsertLast(PPNODE Head,int iNo)
{
	PNODE newn = NULL;
	PNODE temp = *Head;

	newn = (PNODE)malloc(sizeof(NODE));
	newn->data = iNo;
	newn->next = NULL;
	newn->prev = NULL;

	if(*Head == NULL)
	{
		*Head = newn;
	}
	else
	{
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		
		temp->next = newn;
		newn->prev = temp;
	}
}


void InsertAtPosition(PPNODE Head,int iNo, int iPos)
{
	int iSize = 0,i =0;

	iSize = Count(*Head);

	PNODE temp = *Head;
	PNODE newn = NULL;

	if((iPos < 1) || (iPos > iSize+1))
	{
		return;
	}

	if(iPos == 1)
	{
		InsertFirst(Head,iNo);
	}
	else if(iPos == iSize +1)
	{
		InsertLast(Head,iNo);
	}
	else
	{	
		newn = (PNODE)malloc(sizeof(NODE));
		newn->data = iNo;
		newn->next = NULL;
		newn->prev = NULL;


		for(i=1;i<iPos-1;i++)
		{
			temp = temp->next;
		}

		newn->next = temp->next;
		(temp->next)->prev = newn;
		temp->next = newn;
		newn->prev = temp;
	}
}

void DeleteFirst(PPNODE Head)
{	

	if(*Head == NULL)
	{
		return;
	}
	if((*Head)->next == NULL)
	{
		free(*Head);
		*Head = NULL;
	}
	else
	{
		*Head = (*Head)->next;
		free((*Head)->prev);
		(*Head)->prev = NULL;
	}
}

void Display(PNODE Head)
{
	while(Head != NULL)
	{
		printf("|%d|<=>",Head->data);
		Head = Head->next;
	}
	printf("NULL\n");
}
void DeleteLast(PPNODE Head)
{	
	PNODE temp = *Head;

	if(*Head == NULL)
	{
		return;
	}
	if((*Head)->next == NULL)
	{
		free(*Head);
		*Head = NULL;
	}
	else
	{	
		while(temp->next->next != NULL)
		{
			temp = temp->next;
		}

		free(temp->next);
		temp->next = NULL;
	}
}
void DeleteAtPosition(PPNODE Head, int iPos)
{
	int iSize = 0,i =0;

	iSize = Count(*Head);

	PNODE temp = *Head;
	PNODE target = NULL;

	if((iPos < 1) || (iPos > iSize))
	{
		return;
	}

	if(iPos == 1)
	{
		DeleteFirst(Head);
	}
	else if(iPos == iSize)
	{
		DeleteLast(Head);
	}
	else
	{	
		for(i=1;i<iPos-1;i++)
		{
			temp = temp->next;
		}

		/*
		target = temp->next;
		temp->next =target->next;	
		free(target);
		target->prev = temp;
		*/
		temp->next = temp->next->next;
		free(temp->next->prev);
		temp->next->prev = temp;
	}
}
int main()
{
	PNODE First = NULL;
	int iOption = 1,iValue = 0, iPos = 0,iRet = 0;

	while(iOption != 0)
	{
		printf("\n------------------------------------------------\n");
		printf("Select the option \n");
		printf("1: Insert node at first position \n");
		printf("2: Insert node at last position\n");
		printf("3: Insert node at any position\n");
		printf("4: Delete node at first position\n");
		printf("5: Delete node at last position\n");
		printf("6: Delete node from any position\n");
		printf("7: Display Linked List\n");
		printf("8: Count the nodes of Linked List\n");	
		printf("0: Exit the Application\n\n");
		
		scanf("%d",&iOption);
		printf("\n------------------------------------------------\n");
		switch(iOption)
		{
			case 1:
				printf("Enter the data you want to insert: ");
				scanf("%d",&iValue);
				InsertFirst(&First,iValue);
				break;

			case 2:
				printf("Enter the data you want to insert: ");
				scanf("%d",&iValue);
				InsertLast(&First,iValue);
				break;

			case 3:
				printf("Enter the data you want to insert: ");
				scanf("%d",&iValue);
				printf("Enter the position: ");
				scanf("%d",&iPos);
				InsertAtPosition(&First,iValue,iPos);
				break;

			case 4:
				DeleteFirst(&First);
				break;
			
			case 5:
				DeleteLast(&First);
				break;

			
			case 6:
				printf("Enter the position: ");
				scanf("%d",&iPos);
				DeleteAtPosition(&First,iPos);
				break;
			
			case 7:
				printf("Content of Linked List are :\n");
				Display(First);
				break;

			case 8:
				iRet = Count(First);
				printf("Number of Nodes in Linked List are : %d\n",iRet);
				break;

			case 0:
				printf("Thank you for using Linked List Application\n");
				break;

			default:
				printf("Please enter the valid Option\n");
				break;
		}
	}
	
	return 0;
}