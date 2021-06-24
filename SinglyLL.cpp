#include<iostream>
using namespace std;

/*
struct node 
{
	int data;
	struct node *next;
};


typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;
*/

typedef struct node
{
	int data;
	struct node *next;
}NODE, *PNODE;

class SinglyLL
{
private:
	PNODE Head;
	int iSize;

public:
	SinglyLL()
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

		while(temp != NULL)
		{
			cout<<temp->data<<"\t";
			temp = temp->next;
		}
		cout<<"\n";
	}
	void InsertFirst(int iNo)
	{	
		PNODE newn = NULL;

		newn = new NODE;
		newn->data = iNo;
		newn->next = NULL;

		if(Head == NULL)
		{
			Head = newn;
		}
		else
		{	
			newn->next = Head;
			Head = newn;
		}
		iSize++;
	}

	void InsertLast(int iNo)
	{
		PNODE newn = NULL;
		PNODE temp = Head;
		
		newn = new NODE;
		newn->data = iNo;
		newn->next = NULL;

		if(Head == NULL)
		{
			Head = newn;
		}
		else
		{	
			while(temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = newn;
		}
		iSize++;
	}

	void InsertAtPosition(int iNo,int iPos)
	{
		PNODE newn = NULL;
		PNODE temp = Head;
		int s = Count();

		newn = new NODE;
		newn->data = iNo;
		newn->next = NULL;

		if((iPos < 1) || (iPos > s+1))
		{
			return;
		}
		else if(iPos == 1)
		{
			InsertFirst(iNo);
		}
		else if(iPos == s+1)
		{
			InsertLast(iNo);
		}
		else
		{	
			newn = new NODE;
			newn->data = iNo;
			newn->next = NULL;
			
			for(int i=1;i<iPos-1;i++)
			{
				temp = temp->next;
			}
			newn->next = temp->next;
			temp->next = newn;
		}
		iSize++;
	}

	void DeleteFirst()
	{
		if(Head == NULL)
		{
			return;
		}	
		else
		{
			PNODE temp = Head;
			Head = Head->next;
			delete temp;
			iSize--;
		}
		

		/*
		if(Head != NULL)
		{
			PNODE temp = Head;
			Head = Head->next;
			delete temp;
			iSize--;
		}
		*/
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
			Head =NULL;
			iSize--;
		}
		else
		{
			PNODE temp = Head;

			while(temp->next->next != NULL)
			{
				temp = temp->next;
			}
			delete temp->next;
			temp->next = NULL;
			iSize--;
		}
		
	}

	void DeleteAtPosition(int iPos)
	{
		PNODE temp = Head;
		PNODE target = NULL;
		int s = Count();

		if((iPos<1) || (iPos > s))
		{
			return;
		}

		if(iPos == 1)
		{
			DeleteFirst();
		}
		else if(iPos == s)
		{
			DeleteLast();
		}
		else
		{
			for(int i =1;i<iPos;i++)
			{
				temp = temp->next;
			}
			target = temp->next;
			temp->next = temp->next->next;
			delete target;
			iSize--;
		}

	}



};
int main()
{
	int iChoice = 1,iValue = 0,iPos=0;

	SinglyLL obj1;

	while(iChoice != 0)
	{
		cout<<"\n--------------------------------------------------------\n";
		cout<<"Select the option \n\n";
		cout<<"1: Insert at first position\n";
		cout<<"2: Insert at last position \n";
		cout<<"3: Insert at any position \n";
		cout<<"4: Delete from first position \n";
		cout<<"5: Delete from last position \n";
		cout<<"6: Delete from any position \n";
		cout<<"7: Display the Linked List \n";
		cout<<"8: Count the no.of elements \n";
		cout<<"0: Exit the application\n\n";

		cout<<"Enter your choice : ";
		cin>>iChoice;
		
		cout<<"\n--------------------------------------------------------\n";

		switch(iChoice)
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
				cout<<"Enter the position :";
				cin>>iPos;
				cout<<"Enter the data you want to insert :";
				cin>>iValue;
				obj1.InsertAtPosition(iValue,iPos);
				break;

			case 4:
				obj1.DeleteFirst();
				break;

			case 5:
				obj1.DeleteLast();
				break;

			case 6:
				cout<<"Enter the position :";
				cin>>iPos;
				obj1.DeleteAtPosition(iPos);
				break;

			case 7:
				cout<<"Linked List \n";
				obj1.Display();
				break;

			case 8:
				iValue = obj1.Count();
				cout<<"Number of elements are : "<<iValue<<"\n";
				break;

			case 0:
				cout<<"Thank you for using Linked List Application\n";
				break;

			default:
				cout<<"Enter the valid choice";
				break;
		}
	}
	return 0;
}