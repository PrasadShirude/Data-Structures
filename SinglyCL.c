#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node * next;
}NODE,*PNODE,**PPNODE;

int Count(PNODE Head,PNODE Tail)
{
	PNODE temp = Head;
	int iCnt = 0;
	do
	{
		iCnt++;
		temp = temp->next;
	}while(temp != Tail->next);
	return iCnt;
}
void InsertFirst(PPNODE Head,PPNODE Tail,int iNo)
{
	PNODE newn =  NULL;

	newn = (PNODE)malloc(sizeof(NODE));
	newn->data = iNo;
	newn->next = NULL;

	if((*Head == NULL) && (*Tail == NULL))
	{
		*Head = newn;
		*Tail = newn;
	}
	else
	{
		newn->next = *Head;
		*Head = newn;
	}
	(*Tail)->next = *Head;
	
}

void InsertLast(PPNODE Head,PPNODE Tail,int iNo)
{	
	PNODE newn =NULL;

	newn = (PNODE)malloc(sizeof(NODE));
	newn->data = iNo;
	newn->next = NULL;

	if((*Head == NULL) && (*Tail == NULL))
	{
		*Head = newn;
		*Tail = newn;
	}
	else
	{
		(*Tail)->next = newn;
		*Tail = newn;;
	}
	(*Tail)->next = *Head;
}

void InsertAtPosition(PPNODE Head,PPNODE Tail,int iNo,int iPos)
{
	int iSize = Count(*Head,*Tail);

	if((iPos < 1) || (iPos > iSize+1))
	{
		return;
	}
	else if(iPos == 1)
	{
		InsertFirst(Head,Tail,iNo);
	}
	else if(iPos == iSize+1)
	{
		InsertLast(Head,Tail,iNo);
	}
	else
	{
		PNODE temp = *Head;
		PNODE newn = NULL;

		newn = (PNODE)malloc(sizeof(NODE));
		newn->data = iNo;
		newn->next = NULL;

		for(int i = 1;i<iPos-1;i++)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		temp->next = newn;
		
		(*Tail)->next = *Head;
	}
}
void DeleteFirst(PPNODE Head, PPNODE Tail)
{	
	int iSize = Count(*Head,*Tail);

	if((*Head == NULL) && (*Tail == NULL))
	{	
		printf("Linked List is Empty\n");
		return;
	}
	else if(iSize == 1)
	{
		free(*Head);
		*Head = NULL;
		*Tail = NULL;
	}
	else
	{	
		PNODE temp = *Head;

		*Head = (*Head)->next;
		free(temp);

		(*Tail)->next = *Head;
	}
}

void DeleteLast(PPNODE Head,PPNODE Tail)
{
	int iSize = Count(*Head,*Tail);

	if(iSize == 0)
	{
		printf("Linked List is Empty\n");
		return;
	}
	else if(iSize == 1)
	{
		free(*Head);
		*Head = NULL;
		*Tail = NULL;
	}
	else
	{
		PNODE temp = NULL;

		temp = *Head;
		while(temp->next != (*Tail))
		{
			temp = temp->next;
		}
		free(temp->next);
		*Tail = temp;
	}
	(*Tail)->next = *Head;
}

void DeleteAtPosition(PPNODE Head,PPNODE Tail,int iPos)
{
	int iSize = Count(*Head,*Tail);

	if((iPos < 1) || (iPos > iSize))
	{
		return;
	}
	else if(iPos == 1)
	{
		DeleteFirst(Head,Tail);
	}
	else if(iPos == iSize)
	{
		DeleteLast(Head,Tail);
	}
	`
	{
		PNODE temp = *Head;
		PNODE target = NULL;
		for(int i = 1;i<iPos-1;i++)
		{
			temp = temp->next;
		}
		target = temp->next;
		temp->next = temp->next->next;
		free(target);
	}
}
void Display(PNODE Head,PNODE Tail)
{	
	PNODE temp = Head;
	/*while(temp != Tail)
	{
		printf("|%d|->",temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
	*/

	do
	{
		printf("|%d|->",temp->data);
		temp = temp->next;
	}while(temp != Tail->next);
	 
}

int SearchFirstOccurence(PPNODE Head,PPNODE Tail,int iNo)
{
	int iCnt = 0;

	PNODE temp = *Head;
	while(temp != *Tail)
	{	
		iCnt++;
		if(temp->data == iNo)
		{	
			break;
		}
		temp = temp->next;
	}
	return iCnt;
}


int SearchLastOccurence(PPNODE Head,PPNODE Tail,int iNo)
{
	int iCnt = 0,iRet = 0;

	PNODE temp = *Head;
	while(temp != *Tail)
	{	
		iCnt++;
		if(temp->data == iNo)
		{	
			iRet = iCnt;
		}
		temp = temp->next;
	}
	return iRet;
}

int SearchAllOccurence(PPNODE Head,PPNODE Tail,int iNo)
{
	int iCnt = 0;

	PNODE temp = *Head;
	do
	{	
		if(temp->data == iNo)
		{	
			iCnt++;
		}
		temp = temp->next;
	}while(temp != (*Tail)->next);
	return iCnt;
}
int main()
{
	PNODE First = NULL;
	PNODE Last = NULL;

	int iChoice = 1, iRet = 0, iValue = 0, iPos = 0;

	while(iChoice != 0)
	{
		printf("\n-----------------------------------------------------------\n");
		printf("MENU\n");
		printf("1: Insert First\n");
		printf("2: Insert Last\n");
		printf("3: Insert at any position\n");
		printf("4: Delete First\n");
		printf("5: Delete Last\n");
		printf("6: Delete at given position\n");
		printf("7: Display \n");
		printf("8: Count\n");
		printf("9: Search First Occcurence of number \n");
		printf("10: Search all Occcurence of number\n");
		printf("11: Search Last Occcurence of number \n");
		printf("0: Exit\n\n");

		printf("Enter your Choice : ");
		scanf("%d",&iChoice);
		printf("\n-------------------------------------------------------------\n");

		switch(iChoice)
		{
			case 1:
				printf("Enter the data you want to isnert : ");
				scanf("%d",&iValue);
				InsertFirst(&First,&Last,iValue);
				break;

			case 2:
				printf("Enter the data you want to isnert : ");
				scanf("%d",&iValue);
				InsertLast(&First,&Last,iValue);
				break;

			case 3:
				printf("Enter position : ");
				scanf("%d",&iPos);
				printf("Enter the data you want to isnert : ");
				scanf("%d",&iValue);
				InsertAtPosition(&First,&Last,iValue,iPos);
				break;

			case 4:
				DeleteFirst(&First,&Last);
				break;

			case 5:
				DeleteLast(&First,&Last);
				break;

			case 6:
				printf("Enter position : ");
				scanf("%d",&iPos);
				DeleteAtPosition(&First,&Last,iPos);
				break;

			case 7:
				printf("Content of Linked List \n");
				Display(First,Last);
				break;

			case 8:
				iRet = Count(First,Last);
				printf("Number of nodes are : %d",iRet);
				break;

			case 9:
				printf("Enter number you want to Search : ");
				scanf("%d",&iValue);
				iRet = SearchFirstOccurence(&First,&Last,iValue);
				printf("\nFirst Occcurence of %d was found at %d \n",iValue,iRet);
				break;

			case 10:
				printf("Enter number you want to Search : ");
				scanf("%d",&iValue);
				iRet = SearchAllOccurence(&First,&Last,iValue);
				printf("\nTotal Occcurences of %d are %d \n",iValue,iRet);
				break;

			case 11:
				printf("Enter number you want to Search : ");
				scanf("%d",&iValue);
				iRet = SearchLastOccurence(&First,&Last,iValue);
				printf("\nFirst Occcurence of %d was found at %d \n",iValue,iRet);
				break;

			case 0:
				printf("Thank You\n");
				break;

			default:
				printf("Enter valid Choice\n");
				break;
		}
	}
	return 0;
}