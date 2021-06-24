#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node *next;
}NODE,*PNODE;


class Queue
{
private:
	PNODE Head;
	PNODE Tail;
	int iSize;

public:
	Queue();
	~Queue();
	void EnQueue(int);
	int DeQueue();
	void IsEmpty();
	void Display();
	int Count();


};

Queue::Queue()
{
	this->Head = NULL;
	this->Tail = NULL;
	this->iSize = 0;
}

Queue::~Queue()
{
	PNODE temp = NULL;
	while(Head != Tail->next)
	{	
		temp = Head;
		Head = Head->next;
		delete temp;
	}
}

void Queue::EnQueue(int iNo)
{	
	PNODE newn = NULL;

	newn = new NODE();
	newn->data = iNo;
	newn->next = NULL;

	if(iSize == 0)
	{
		Head = newn;
		Tail = newn;
		iSize++;
	}
	else
	{
		Tail->next = newn;
		//newn->next = Tail->next;
		Tail = newn;
		iSize++;
	}
	Tail->next = Head;
	
}

int Queue::DeQueue()
{
	int iRet = -1;
	if(iSize == 0)
	{
		cout<<"Queue is empty\n";
	}
	else
	{
		PNODE temp = Head;
		
		Head = Head->next;
		iRet = temp->data;

		delete temp;
		Tail->next = Head;
		iSize--;
	}
	return iRet;	
}

void Queue::IsEmpty()
{
	if(iSize == 0)
	{
		cout<<"Queue is empty\n";
	}
	else
	{
		cout<<"Queue is not empty\n";
		cout<<"Queue contains "<<iSize<<" elements\n";
	}
}

void Queue::Display()
{
	PNODE temp = Head;

	do
	{
		cout<<"|"<<temp->data<<"|\t";
		temp = temp->next;
	}while(temp != Tail->next);
	cout<<"\n";
}

int Queue::Count()
{
	return iSize;
}
int main()
{	
	Queue *qobj = new Queue();

	int iChoice = 1, iRet = 0, iValue =0 ;

	while(iChoice != 0)
	{
		
		cout<<"\n-----------------------------------------------------------------------\n";
		cout<<"\tMENU\n\n";
		cout<<"1: Add element to Queue\n";
		cout<<"2: Remove element from Queue\n";
		cout<<"3: Display the elements\n";
		cout<<"4: Count the elements\n";
		cout<<"5: IsEmpty\n";
		cout<<"0: Exit\n\n";

		cout<<"Enter your choice : ";
		cin>>iChoice;
		cout<<"\n-----------------------------------------------------------------------\n";

		switch(iChoice)
		{
			case 1:
				cout<<"Enter the element : ";
				cin>>iValue;
				qobj->EnQueue(iValue);
				break;

			case 2:
				iRet = qobj->DeQueue();
				cout<<"Removed element is : "<<iRet<<"\n";
				break;

			case 3:
				cout<<"Queue Contents are \n";
				qobj->Display();
				break;

			case 4:
				iRet = qobj->Count();
				cout<<"Number of elements are : "<<iRet<<"\n";
				break;

			case 5:
				qobj->IsEmpty();
				break;

			case 0:
				cout<<"Thank You for using Application\n";
				delete qobj;
				break;

			default:
				cout<<"InValid Choice\n";
		}
	}
	return 0;
}