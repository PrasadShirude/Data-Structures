#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node *next;
}NODE,*PNODE;

class Stack
{
private:
	PNODE Head;
	int iSize;

public:
	Stack();			// Construtor
	~Stack();			// Destructor
	void PUSH(int);		// void InsertFirst(int);
	int POP();			// void DeleteFirst();
	void Display();
	int Count();
	int PEEK();

};

Stack::Stack()
{
	this->Head = NULL;
	this->iSize = 0;
}

Stack::~Stack()
{
	cout<<"Inside Destructor\n";
	PNODE temp = NULL;

	while(Head != NULL)
	{
		temp = Head;
		Head = Head->next;
		delete temp;		
	}
}

void Stack::PUSH(int iNo)
{	
	PNODE newn = NULL;

	newn = new NODE;
	newn->data = iNo;
	newn->next = NULL;

	newn->next = Head;
	Head =newn;
	iSize++;
}

int Stack::POP()
{	
	int iRet = -1;
	if( Head == NULL)
	{	
		cout<<"Stack is empty\n";
	}
	else
	{	
		PNODE temp = Head;
		Head = Head->next;
		iRet = temp->data;
		
		delete temp;
		iSize--;
	}
	return iRet;
}

void Stack::Display()
{
	PNODE temp = Head;


	while(temp != NULL)
	{
		cout<<"|"<<temp->data<<"|\n";
		temp = temp->next;
	}
	cout<<"\n";
}

int Stack::Count()
{	
	return this->iSize;
}

int Stack::PEEK()
{
	//int iRet = -1;
	if( Head == NULL)
	{	
		cout<<"Stack is empty\n";
		return -1;
	}
	else
	{	
		//PNODE temp = Head;
		return Head->data;
	}
	//return iRet;
}
int main()
{
	Stack *sobj = new Stack;			// Inplicitly call Constructor

	int iChoice = 1, iRet = 0, iValue = 0;

	while(iChoice != 0)
	{
		cout<<"\n-------------------------------------------------------------------\n";
		cout<<"\t MENU\n\n";
		cout<<"1: Push the element\n";
		cout<<"2: Pop the element\n";
		cout<<"3: Display the elements\n";
		cout<<"4: Count the elements\n";
		cout<<"5: Peek element\n";
		cout<<"0: Exit\n\n";

		cout<<"Enter your choice : ";
		cin>>iChoice;
		cout<<"\n--------------------------------------------------------------------\n";

		switch(iChoice)
		{
			case 1:
				cout<<"Enter the element you want to push : ";
				cin>>iValue;
				sobj->PUSH(iValue);
				 break;

			case 2:
				iRet = sobj->POP();
				cout<<"Poped element is : "<<iRet<<"\n";
				break;

			case 3:
				cout<<"Content of stack are : \n";
				sobj->Display();
				break;

			case 4:
				iRet = sobj->Count();
				cout<<"Number of element are : "<<iRet<<"\n";
				break;

			case 5:
				iRet = sobj->PEEK();
				cout<<"Peek element is : "<<iRet<<"\n";
				break;

			case 0:
				cout<<"Thank You!!!!\n";
				delete sobj;			// Its implecitly calls destructor
				break;

			default:
				cout<<"Enter the valid \n";
				break;
		}
	}
	return 0;
}