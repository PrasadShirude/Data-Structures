#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
}NODE,*PNODE,**PPNODE;

int Count(PNODE Head,PNODE Tail)
{
	PNODE temp = Head;
	int iCnt = 0;
	
	while(temp != Tail->next)
	{	
		iCnt++;
		temp = temp->next;
	}
	return iCnt;
}

void Display(PNODE Head,PNODE Tail)
{
	PNODE temp = Head;

	while(temp != Tail->next)
	{
		printf("%d\t",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void InsertFirst(PPNODE Head,PPNODE Tail,int iNo)
{	
	PNODE newn = NULL;

	newn = (PNODE)malloc(sizeof(NODE));
	newn->data = iNo;
	newn->next = NULL;
	newn->prev = NULL;

	if((*Head == NULL) && (*Tail == NULL))
	{
		*Head = newn;
		*Tail = newn;
	}
	else
	{
		newn->next = *Head;
		*Head = newn;
		newn->next->prev = newn;
		newn->prev = *Head;
	}
	(*Tail)->next = *Head;
	(*Head)->prev = *Tail;
}

void InsertLast(PPNODE Head,PPNODE Tail,int iNo)
{
	PNODE newn = NULL;

	newn = (PNODE)malloc(sizeof(NODE));
	newn->data = iNo;
	newn->next = NULL:
	newn->prev = NULL;

	if((*Head == NULL) && (*Tail == NULL))
	{
		*Head = newn;
		*Tail = newn;
	}
	else
	{
		PNODE temp = *Head;

		do
		{
			temp = temp->next;
		}while(temp != (*Tail)->next);

		
	}
}

int main()
{
	PNODE First = NULL;
	PNODE Last =  NULL;

	int iChoice = 1,iValue = 0,iRet = 0,iPos = 0;

	while(iChoice != 0)
	{
		printf("\n-----------------------------------------------------------------\n");
		printf("\tMENU\n\n");
		printf("1: Insert First\n");
		printf("2: Insert Last\n");
		printf("3: Insert at any position\n");
		printf("4: Delete First\n");
		printf("5: Delete Last\n");
		printf("6: Delete from given position\n");
		printf("7: Display Linked List\n");
		printf("8: Count\n");
		printf("0: Exit\n\n");

		printf("Select your choice : ");
		scanf("%d",&iChoice);
		printf("\n------------------------------------------------------------------\n");

		switch(iChoice)
		{
			case 1:
				printf("Enter the data you want to inesrt : ");
				scanf("%d",&iValue);
				InsertFirst(&First,&Last,iValue);
				break;

			case 7:
				Display(First,Last);
				break;

			case 8:
				iRet = Count(First,Last);
				printf("Total number of nodes are %d\n",iRet);
				break;

			case 0:
				printf("Thank You \n");
				break;

			default:
				printf("Enter the valid choice\n");
				break;
		}
	}

	return 0;
}