#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node **PPNODE;

void InsertLast(PPNODE Head,int iNo)
{
	PNODE newn = NULL;
	PNODE temp = *Head;

	newn = (PNODE)malloc(sizeof(NODE));
	newn->data = iNo;
	newn->next = NULL;

	if(*Head == NULL)
	{
		*Head == newn;
	}
	else
	{
		while(temp->next != NULL)
		{	
			temp = temp->next;
		}
		temp->next = newn;
	}

}

void InsertFirst(PPNODE Head,int iNo)
{
	PNODE newn = NULL;

	newn = (PNODE)malloc(sizeof(NODE));
	newn->data = iNo;
	newn->next = NULL;

	if(*Head == NULL)
	{
		*Head = newn;
	}
	else
	{
		newn->next = *Head;
		*Head = newn;
	}

}
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

void InsertAtPosition(PPNODE Head,int iNo,int iPos)
{
	int iSize = 0,i =0;
	iSize = Count(*Head);
	PNODE temp = *Head;

	PNODE newn = NULL;

	if((iPos < 1) || (iPos > iSize+1))	// Invalid Position
	{
		return;
	}
	else if(iPos == 1)						// First position
	{
		InsertFirst(Head,iNo);
	}
	else if(iPos == iSize+1)			// Lasr position
	{
		InsertLast(Head,iNo);
	}
	else								// between first and last position
	{	
		newn = (PNODE)malloc(sizeof(NODE));
		newn->data = iNo;
		newn->next = NULL;
		
		for(i=1;i<iPos-1;i++)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		temp->next = newn;

	}
}



void Display(PNODE Head)
{	
	PNODE temp = Head;
	while(temp != NULL)
	{
		printf("|%d|->",temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}



void DeleteFirst(PPNODE Head)
{
	PNODE temp = *Head;

	if(*Head == NULL)
	{
		return;
	}
	else if((*Head)->next==NULL)
	{
		free(*Head);
		*Head = NULL;
	}
	else
	{
		*Head = (*Head)->next;
		free(temp);
	}
}

void DeleteLast(PPNODE Head)
{
	PNODE temp = *Head;

	if(*Head == NULL)
	{
		return;
	}
	else if((*Head)->next==NULL)
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
void DeleteAtPosition(PPNODE Head,int iPos)
{
	int iSize = 0,i =0;
	iSize = Count(*Head);
	PNODE temp = *Head;
	PNODE target = NULL;
	if((iPos < 1) || (iPos > iSize))	// Invalid Position
	{
		return;
	}
	else if(iPos == 1)					// First position
	{
		DeleteFirst(Head);
	}
	else if(iPos == iSize)			// Lasr position
	{
		DeleteLast(Head);
	}
	else								// between first and last position
	{	
	
		for(i=1;i<iPos-1;i++)
		{
			temp = temp->next;
		}
		target = temp->next;
		temp->next = target->next;
		free(target);	
	}
}
int main()
{
	PNODE First = NULL;
	int iRet = 0, iOption = 1,iValue =0,iPos = 0;

	while(iOption != 0)
	{	
		printf("\n--------------------------------------------\n");
		printf("Enter your operation on linked list\n");
		printf("1: Insert node at first position\n");
		printf("2: Insert node at Last position\n");
		printf("3: Insert node at given position\n");
		printf("4: Delete node at first position\n");
		printf("5: Delete node at Last position\n");
		printf("6: Delete node at given position\n");
		printf("7: Display the content of Linked List\n");
		printf("8: Count number of nodes in Linked List\n");
		printf("0: Exit the application\n");
		scanf("%d",&iOption);

		printf("\n--------------------------------------------\n");

		switch(iOption)
		{
			case 1:
				printf("Enter data to insert :");
				scanf("%d",&iValue);
				InsertFirst(&First,iValue);
				break;

			case 2:
				printf("Enter data to insert :");
				scanf("%d",&iValue);
				InsertLast(&First,iValue);
				break;

			case 3:

				printf("Enter data to insert :");
				scanf("%d",&iValue);
				printf("Enter position to insert\n");
				scanf("%d",&iPos);
				InsertAtPosition(&First,iValue,iPos);
				break;

			case 4:
				DeleteFirst(&First);
				printf("Node deleted from first position\n");
				break;	

			case 5:
				DeleteLast(&First);
				printf("Node deleted from last position\n");
				break;

			case 6:
				printf("Enter position to insert\n");
				scanf("%d",&iPos);
				DeleteAtPosition(&First,iPos);
				break;


			case 7:
				printf("Nodes of linked list are :\n");
				Display(First);
				break;

			case 8:
				iRet = Count(First);
				printf("Number of nodes are : %d\n",iRet );	
				break;

			case 0:
				printf("Thank you for using Linked List application\n");
				break;

			default:
			  	printf("Please enter valid number \n");
			  	break;

		}//End of switch
	}//end of while
	
	return 0;
}//end of main