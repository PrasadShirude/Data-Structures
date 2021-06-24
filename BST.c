// Binary searc Tree BST

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node
{
	int data;
	struct node *lchild;
	struct node *rchild;
}NODE,*PNODE,**PPNODE;

void InsertNode(PPNODE Head,int iNo)
{
	PNODE temp = *Head;

	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(NODE));
	newn->data = iNo;
	newn->lchild = NULL;
	newn->rchild = NULL;

	if(*Head == NULL)	// Root node
	{
		*Head = newn;
	}
	else				// Tree contains atleast one node
	{
		while(1)	// unconditional looop
		{
			if(iNo > temp->data)
			{
				if(temp->rchild == NULL)
				{
					temp->rchild = newn;
					break;
				}
				temp = temp->rchild;
			}
			else if(iNo < temp->data)
			{
				if(temp->lchild == NULL)
				{
					temp->lchild = newn;
					break;
				}
				temp = temp->lchild;
			}
			else if(iNo == temp->data)
			{
				printf("Duplicate Element\n");
				free(newn);
				return;
			}
		}
	}

}

void Inorder(PNODE Head)	// LDR
{
	if(Head != NULL)
	{
		Inorder(Head->lchild);
		printf("%d\t",Head->data );
		Inorder(Head->rchild);
	}
}

void Preorder(PNODE Head)	// DLR
{
	if(Head != NULL)
	{
		printf("%d\t",Head->data );
		Preorder(Head->lchild);
		Preorder(Head->rchild);
	}
}

void Postorder(PNODE Head)	// LRD
{
	if(Head != NULL)
	{
		Postorder(Head->lchild);
		Postorder(Head->rchild);
		printf("%d\t",Head->data );
	}
}

void Count(PNODE Head,int *iCnt)
{	
	if(Head != NULL)
	{
		(*iCnt)++;
		Count(Head->lchild,iCnt);
		Count(Head->rchild,iCnt);
	}
}

void CountLeaf(PNODE Head,int *iCnt)
{	
	if(Head != NULL)
	{	
		if((Head->lchild == NULL) && (Head->rchild) == NULL)
		{
			(*iCnt)++;
		}
		CountLeaf(Head->lchild,iCnt);
		CountLeaf(Head->rchild,iCnt);
	}
}

void CountParent(PNODE Head,int *iCnt)
{	
	if(Head != NULL)
	{	
		if((Head->lchild != NULL) || (Head->rchild) != NULL)
		{
			(*iCnt)++;
		}
		CountParent(Head->lchild,iCnt);
		CountParent(Head->rchild,iCnt);
	}
}

bool Search(PNODE Head,int iNo)
{
	if(Head != NULL)
	{
		if(iNo > Head->data)
		{
			return Search(Head->rchild,iNo);
		}
		else if(iNo < Head->data)
		{
			return Search(Head->lchild,iNo);
		}
		else if(iNo == Head->data)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
}

bool SearchX(PNODE Head,int iNo)
{	
	if(Head == NULL)
	{
		return false;
	}
	else
	{
		while(1)
		{
			if(iNo > Head->data)
			{
				if(Head->rchild == NULL)
				{
					break;
				}
				Head = Head->rchild;
			}
			else if(iNo < Head->data)
			{
				if(Head->rchild == NULL)
				{
					break;
				}
				Head = Head->rchild;
			}
			else if(iNo == Head->data)
			{
				break;
			}
		}// end while
		if(Head->data == iNo)
		{
			return true;
		}
		else
		{
			return false;
		}
	}// end else
}// end of function

int main()
{	
	PNODE Root = NULL;

	int iChoice = 1, iValue = 0,iRet = 0,iCnt = 0;
	bool bRet;

	while(iChoice != 0)
	{
		printf("\n-------------------------------------------------------------\n");
		printf("\t\t Menu\n\n");
		printf("\t1: Insert node\n");
		printf("\t2: Display Inorder\n");
		printf("\t3: Display Preorder\n");
		printf("\t4: Display Postorder\n");
		printf("\t5: Count nodes\n");
		printf("\t6: Count Leaf Nodes\n");
		printf("\t7: Count Parent Nodes\n");
		printf("\t8: Search Element\n");
		printf("\t0: Exit\n\n");
		printf("Enter your choice :");
		scanf("%d",&iChoice);

		printf("\n-------------------------------------------------------------\n");

		switch(iChoice)
		{
			case 1:
				printf("Enter data : ");
				scanf("%d",&iValue);
				InsertNode(&Root,iValue);
				break;

			case 2:
				printf("Inorder Traversal\n");
				Inorder(Root);
				printf("\n");
				break;

			case 3:
				printf("Preorder Traversal\n");
				Preorder(Root);
				printf("\n");
				break;
			
			case 4:
				printf("Postorder Traversal\n");
				Postorder(Root);
				printf("\n");
				break;	

			case 5:
				iCnt = 0;
				Count(Root,&iCnt);
				printf("No.of nodes in tree are : %d\n",iCnt);
				iCnt = 0;
				break;

			case 6:
				iCnt = 0;
				CountLeaf(Root,&iCnt);
				printf("No.of leaf nodes in tree are : %d\n",iCnt);
				iCnt = 0;
				break;

			case 7:
				iCnt = 0;
				CountParent(Root,&iCnt);
				printf("No.of leaf nodes in tree are : %d\n",iCnt);
				iCnt = 0;
				break;
			
			case 8:
				printf("Enter the Element you want to searc : ");
				scanf("%d",&iValue);
				bRet = SearchX(Root,iValue);
				if(bRet == true)
				{
					printf("%d present in BST\n",iValue);
				}
				else
				{
					printf("%d not present in BST\n",iValue);
				}
				break;

			case 0:
				printf("THANK YOU!!!\n");
				break;

			default:
				printf("Enter valid choice\n");
				break;
		}// end switch
	}// end of while
	return 0;
}

