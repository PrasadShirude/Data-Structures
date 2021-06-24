#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
}NODE,*PNODE;


class DoublyLL
{
private:
	PNODE Head;
	int iSize;

public:
	 DoublyLL()
	{	
		Head = NULL;
		iSize = 0;
	}

	int Count()
	{
		return iSize;
	}

	void Display()
	{	
		PNODE temp = Head;
		cout<<"|";
		while(temp != NULL)
		{
			cout<<temp->data<<"|<=>|";
			temp = temp->next;
		}
		cout<<"NULL|\n";
	}
	void InsertFirst(int iNo)
	{	
		PNODE newn = NULL;

		newn = new NODE;
		newn->data = iNo;
		newn->next = NULL;
		newn->prev = NULL;

		if(Head == NULL)
		{
			Head = newn;
		}
		else
		{
			newn->next = Head;
			Head = newn;
			newn->prev = Head;
			newn->next->prev = newn;
		}
		iSize++;
	}

	
	void InsertLast(int iNo)
	{
		PNODE newn = NULL;

		newn = new NODE;
		newn->data = iNo;
		newn->next = NULL;
		newn->prev = NULL;

		if(Head == NULL)
		{
			Head = newn;
		}
		else
		{
			PNODE temp = Head;

			while(temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = newn;
			newn->prev = temp;
			newn->next = NULL;
		}
		
		iSize++;
	}

	void InsertAtPosition(int iNo,int iPos)
	{
		PNODE temp = Head;

		PNODE newn = NULL;

		if((iPos < 1) || (iPos > iSize +1))
		{
			return;
		}
		else if(iPos == 1)
		{
			InsertFirst(iNo);
		}
		else if(iPos == iSize+1)
		{
			InsertLast(iNo);
		}
		else
		{
			newn = new NODE;
			newn->data = iNo;
			newn->next = NULL;
			newn->prev = NULL;

			int i =0;
			for(i=1;i<iPos-1;i++)
			{
				temp = temp->next;
			}
			newn->next = temp->next;
			temp->next = newn;
			newn->prev = temp;
			newn->next->prev = newn;
		}	
		iSize++;
	}
	
	void DeleteFirst()
	{
		if(Head == NULL)
		{
			return;
		}
		else if(Head->next == NULL)
		{
			delete Head;
			Head = NULL;
			iSize--;
		}
		else
		{	PNODE temp = Head;

			Head = Head->next;
			delete temp;
			Head->prev= Head;
			iSize--;
		}
		
	}

	void DeleteLast()
	{
		if(Head == NULL)
		{
			return;
		}
		else if(Head->next == NULL)
		{
			delete Head;
			Head = NULL;
			iSize--;
		}
		else
		{	PNODE temp = Head;

			while(temp->next->next != NULL)
			{
				temp = temp->next;
			}
			delete temp->next;
			temp->next= NULL;
			iSize--;
		}
		
	}

};
int main()
{
	int iOption =1,iValue =0,iRet =0, iPos = 0;

	DoublyLL obj1;

	while(iOption != 0)
	{
		cout<<"\n----------------------------------------------------------\n";
		cout<<"Select the option \n";	
		cout<<"1: Insert at First Position \n";
		cout<<"2: Insert Last\n";
		cout<<"3: Insert at any position\n";
		cout<<"4: Delete First\n";
		cout<<"5: Delete Last\n";
		cout<<"7: Display the content of Linked List\n";
		cout<<"8: Count\n";
		cout<<"0: Exit the application \n\n";

		cout<<"Enter your choice : ";
		cin>>iOption;

		cout<<"\n----------------------------------------------------------\n";

		switch(iOption)
		{
			case 1:
				cout<<"Enter the data you want to insert :";
				cin>>iValue;
				obj1.InsertFirst(iValue);
				break;

			case 2:
				cout<<"Enter the data you want to insert :";
				cin>>iValue;
				obj1.InsertLast(iValue);
				break;

			case 3:
				cout<<"Enter position : ";
				cin>>iPos;
				cout<<"Enter data you want to insert : ";
				cin>>iValue;
				obj1.InsertAtPosition(iValue,iPos);
				break;

			case 4:
				obj1.DeleteFirst();
				break;

			case 5:
				obj1.DeleteLast();
				break;

			case 7:
				obj1.Display();
				break;

			case 8:
				iRet = obj1.Count();
				cout<<"Number of nodes are : "<<iRet<<"\n";
				break;

			case 0:
				cout<<"Thank you for using Marvellous Doubly Linked List\n";
				break;
		
			default:
				cout<<"Enter the valid choice\n";
				break;
		}
	}

	return 0;
}