#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node **PPNODE;

void Add(PPNODE Head,int iNo)
{
	PNODE newn = NULL;
	PNODE temp = *Head;

	newn = (PNODE)malloc(sizeof(NODE));
	newn->data = iNo;
	newn->next = NULL;

	if(*Head == NULL);
	{
		*Head = newn;
	}
	else
	{
		while(temp != NULL)
		{
			temp = temp->next;
		}
		temp->next = newn;

	}
		
}

void Delete(PPNODE Head)
{	
	PNODE temp = *Head;

	if(*Head == NULL)
	{
		return;
	}
	else
	{
		*Head = *Head->next;
		free(temp;)
	}
}
int LastOccurance(PNODE Head, int Value)
{
    int iPos = -1, iCnt = 1;
    if(Head == NULL)
    {
        return -1;
    }
    while(Head != NULL)             // O(N)
    {
        if(Head -> data == Value)
        {
            iPos = iCnt;
        }
        Head = Head -> next;
        iCnt ++;
    }
    return iPos;
}

void Display(PNODE Head)
{
	while(Head != NULL)
		
}

int main()
{
	PNODE First = NULL;
	int iOption = 1,iValue =0;


	while(iOption != 0)
	{	
		printf("\n----------------------------------------------------\n");
		printf("Select the Operation you want to perform on Queue\n");
		printf("1: Add the value to queue \n");
		printf("2: Remove/Delete value from queue \n");
		printf("3: Display the queue \n");
		printf("4: Count the no.of elements in queue\n");
		printf("0: Exit the application\n\n");
		scanf("%d",&iOption);

		printf("\n----------------------------------------------------\n");

		switch(iOption)
		{
			case 1:
				printf("Enter the value you want to add :\n");
				scanf("%d",&iValue);
				Add(&First,iValue);
				break;

			case 0:
				printf("Thank You for using queue application\n");
				break;

			default:
				printf("Select the valid option\n");
				break;
		}
	}
}