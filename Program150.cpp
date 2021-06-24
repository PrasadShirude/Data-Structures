#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node * next;

}NODE,*PNODE;

class SinglyCL
{
private:
	PNODE Head;
	PNODE Tail;
	int iSize;

public:

	SinglyCL()
	{
		Head = NULL;
		Tail = NULL;
		iSize = 0;
	}

	void InsertFirst(int iNo)
	{
		PNODE newn = NULL;

		newn = new NODE;
		newn->data = iNo;
		newn->next = NULL;

		if((Head == NULL) && (Tail == NULL))
		{
			Head = newn;
			Tail = newn;
		}
		else
		{
			newn->next = Head;
			Head = newn;
		}
		iSize++;
		Tail->next = Head;

	}

	void InsertLast(int iNo)
	{
		PNODE newn = NULL;

		newn = new NODE;
		newn->data = iNo;
		newn->next = NULL;

		if((Head == NULL) && (Tail == NULL))
		{
			Head = newn;
			Tail = newn;
		}
		else
		{
			Tail->next = newn;
			Tail = newn;
		}
		iSize++;
		Tail->next = Head;
	}

	void InsertAtPosition(int iPos)
	{
		PNODE temp = Head;

		if((iPos < 1) || (iPos > iSize +1))
		{
			return;
		}

		if()
	}

	void DeleteLast()
	{
		if(iSize == 0)   			//((Head == NULL) && (Tail == NULL))
		{
			return;
		}
		else if(iSize == 1)			//(Head == Tail)   (Head == Tail->next)
		{
			delete Head;
			Head = NULL;
			Tail = NULL;
		}
		else
		{	
			PNODE temp =  Head;

			int i =0;
			for(i=1;i<iSize-1;i++)
			{
				temp = temp->next;
			}
			delete (temp->next);	//delete Tail;
			Tail = temp;
			Tail->next = Head;			
		}
		iSize--;
	}

	void DeleteFirst()
	{
		if(iSize == 0)   			//((Head == NULL) && (Tail == NULL))
		{
			return;
		}
		else if(iSize == 1)
		{
			delete Head;
			Head = NULL;
			Tail = NULL;
		}
		else
		{
			Head = Head->next;
			delete (Tail->next);
			Tail->next = Head;
		}
		iSize--;
	}

	int Count()
	{
		return iSize;
	}

	void Display()
	{	
		int i = 0;
		PNODE temp = Head;
		
		for(i=1;i<=iSize;i++)
		{
			cout<<temp->data<<"\t";
			temp = temp->next;
		}
		cout<<"\n";
	}

};

int main()
{
	SinglyCL obj1;

	int iChoice =1, iValue = 0,iPos = 0, iRet = 0;

	while(iChoice != 0)
	{
		cout<<"\n--------------------------------------------------------------------------\n";
		cout<<"1: Insert First \n";
		cout<<"2: Insert Last \n";
		cout<<"3: Insert At any position \n";
		cout<<"4: Delete First \n";
		cout<<"5: Delete Last \n";
		cout<<"6: Delete at any position \n";
		cout<<"7: Display \n";
		cout<<"8: Count \n";
		cout<<"0: Exit \n\n";

		cout<<"Enter your Choice : ";
		cin>>iChoice;

		cout<<"\n--------------------------------------------------------------------------\n";

		switch(iChoice)
		{
			case 1:
				cout<<"Enter the data to insert : ";
				cin>>iValue;
				obj1.InsertFirst(iValue);
				break;

			case 2:
				cout<<"Enter the data to insert : ";
				cin>>iValue;
				obj1.InsertLast(iValue);
				break;

			case 3:
				cout<<"Enter position : ";
				cin>>iPos;
				cout<<"Enter the data to insert : ";
				cin>>iValue;
				//obj1.InsertAtPosition(iValue,iPos);
				break;

			case 4:
				obj1.DeleteFirst();
				break;

			case 5:
				obj1.DeleteLast();
				break;

			case 6:
				cout<<"Enter position : ";
				cin>>iPos;
				//obj1.DeleteAtPosition(iPos);
				break;

			case 7:
				cout<<"Contents are \n";
				obj1.Display();
				break;

			case 8:
				iRet = obj1.Count();
				cout<<"Number of nodes are : "<<iRet<<"\n";
				break;

			case 0:
				cout<<"Thank You\n";
				break;

			default:
				cout<<"Please enter the valid choice\n";
				break;

		}
	}

	return 0;
}
