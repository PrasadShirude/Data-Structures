#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
}NODE,*PNODE;

class DoublyCL
{
private:
	PNODE Head;
	PNODE Tail;
	int iSize;

public:

	DoublyCL()
	{
		Head = NULL;
		Tail = NULL;
		iSize = 0;
	}

	int Count()
	{
		return iSize;
	}

	void Display()
	{
		PNODE temp = Head;

		int i =0;
		for(i =1;i<=iSize;i++)
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
		newn->prev = NULL;

		if((Head == NULL) && (Tail == NULL))	//if(iSize == 0)
		{
			Head = newn;
			Tail = newn;
		}
		else
		{
			newn->next = Head;			//newn->next = Head;
			Head = newn;				//Head->prev = newn;
			newn->prev = Head;			// Head= newn;
			newn->next->prev = newn;
		}
		Head->prev = Tail;
		Tail->next = Head;
		iSize++;
	}

	void InsertLast(int);
	void InsertAtPosition(int,int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPosition(int);

};


void DoublyCL::InsertLast(int iNo)
{
	PNODE newn = NULL;

	newn = new NODE;
	newn->data = iNo;
	newn->next = NULL;
	newn->prev = NULL;

	if((Head == NULL) && (Tail == NULL))
	{
		Head = newn;
		Tail = newn;
	}
	else
	{
		Tail->next = newn;
		newn->prev = Tail;
		Tail = newn;
	}
	Head->prev = Tail;
	Tail->next = Head;
	iSize++;
}

void DoublyCL::InsertAtPosition(int iNo,int iPos)
{
	if((iPos < 1) || (iPos > iSize+1))
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
		PNODE temp = Head;
		PNODE newn = NULL;

		newn = new NODE;
		newn->data = iNo;
		newn->next = NULL;
		newn->prev = NULL;
		
		int i = 0;
		for(i = 1;i<iPos-1;i++)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		temp->next = newn;
		newn->next->prev = newn;
		newn->prev = temp;

		iSize++;
	}
	
}

void DoublyCL::DeleteFirst()
{
	if(iSize == 0)
	{
		return;
	}
	else if(iSize == 1)
	{
		delete Head;
		Head = NULL;
		Tail = NULL;
		iSize = 0;
	}
	else
	{
		Head = Head->next;
		delete (Head->prev);	// delete (Tail->next);
		Head->prev = Tail;
		Tail->next = Head;
		iSize--;
	}	
}

void DoublyCL::DeleteLast()
{
	if(iSize == 0)
	{
		return;
	}
	else if(iSize == 1)
	{
		delete Head;
		Head = NULL;
		Tail = NULL;
		iSize = 0;

	}
	else
	{	
		Tail = Tail->prev;
		delete (Head->prev);	// delete(Tail->next);
		Tail->next = Head;
		Head->prev = Tail;
		iSize--;
	}
}

void DoublyCL::DeleteAtPosition(int iPos)
{
	if((iPos < 1) || (iPos > iSize))
	{
		return;
	}
	else if(iPos == 1)
	{
		DeleteFirst();
	}
	else if(iPos == iSize)
	{
		DeleteLast();
	}
	else
	{	
		PNODE temp = Head;
				
		int i = 0;
		for(i = 1;i<iPos-1;i++)
		{
			temp = temp->next;
		}
		temp->next = temp->next->next;
		delete (temp->next->prev);
		temp->next->prev = temp;
		iSize--;
	}
}


int main()
{
	DoublyCL obj;

	int iChoice = 1, iValue = 0, iRet = 0, iPos = 0;

	while(iChoice != 0)
	{	
		cout<<"\n----------------------------------------------------\n";

		cout<<"MENU \n";
		cout<<"1: Insert First\n";
		cout<<"2: Insert Last\n";
		cout<<"3: Insert at any position\n";
		cout<<"4: Delete First\n";
		cout<<"5: Delete Last\n";
		cout<<"6: Delete at given position\n";
		cout<<"7: Display\n";
		cout<<"8: Count\n";
		cout<<"0: Exit\n\n";

		cout<<"Enter your choice : ";
		cin>>iChoice;

		cout<<"\n----------------------------------------------------\n";

		switch(iChoice)
		{
			case 1:
				cout<<"Insert the data to insert : ";
				cin>>iValue;
				obj.InsertFirst(iValue);
				break;

			case 2:
				cout<<"Insert the data to insert : ";
				cin>>iValue;
				obj.InsertLast(iValue);
				break;

			case 3:
				cout<<"Enter the position : ";
				cin>>iPos;
				cout<<"Insert the data to insert : ";
				cin>>iValue;
				obj.InsertAtPosition(iValue,iPos);
				break;

			case 4:
				obj.DeleteFirst();
				break;

			case 5:
				obj.DeleteLast();
				break;

			case 6:
				cout<<"Enter position : ";
				cin>>iPos;
				obj.DeleteAtPosition(iPos);
				break;

			case 7:
				cout<<"Content of Linked List are \n";
				obj.Display();
				break;

			case 8:
				iRet = obj.Count();
				cout<<"Number of nodes are : "<<iRet;
				break;

			case 0:
				cout<<"Thank You\n";
				break;

			default:
				cout<<"Enter valid choice \n";
				break;
		}
	}

	return 0;
}