#include<stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void InsertFirst(PPNODE Head,int iNo)
{
	PNODE newn = NULL;
	PNODE temp = *Head;

	newn = (PNODE)malloc(sizeof(NODE));
	newn->data = iNo;
	newn->next = NULL;

	if(*Head == NULL)
	{
		*Head = newn;
		newn->next = *Head;
	}
	else
	{
		newn->next = newn;
		*Head = newn;

		while(temp->next != *Head)
		{
			temp = temp->next;
		}
		temp->next = *Head;
	}
}

void Display(PNODE Head)
{
	while(Head != Head)
	{
		printf("|%d|->",Head->data);
		Head = Head->next;
	}
}
int main()
{
	PNODE First = NULL;

	int iOption =1, iValue = 0;

	while(iOption != 0)
	{	
		printf("\n-----------------------------------------------------------------------\n");
		printf("Select the operaion you want to perform on Singly Linear Linked List \n");
		printf("1: Insert node at first\n");
		printf("7: Display the content of Linked List\n");
		printf("0: Exit the application\n\n");

		printf("Enter your choice: ");
		scanf("%d",&iOption);

		printf("\n-----------------------------------------------------------------------\n");

		switch(iOption)
		{
			case 1:
				printf("Enter data you want to insert\n");
				scanf("%d",&iValue);
				InsertFirst(&First,iValue);
				break;

			case 7:
				printf("Content of Linked List are :\n");
				Display(First);
				break;

			case 0:
				printf("Thank you for using Singly Linear Linked List application\n");
				break;
			
			default:
				printf("Please enter valid choice\n");
				break;
		}

	}
	return 0;
}