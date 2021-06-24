//  Stack using Array

#include<iostream>
using namespace std;

class Stack
{
private:
	int *Arr;
	int iSize;
	int top;

public:
	Stack(int);
	~Stack();
	void Display();
	void Push(int);
	int Pop();
	int Count();
};

Stack::Stack(int iNo)
{	
	iSize = iNo;
	Arr = new int[iSize];
	top = -1;
}

Stack::~Stack()
{
	delete []Arr;
}

void Stack::Display()
{	
	if(top == -1)
	{
		cout<<"Stack is empty\n";
	}
	else
	{
		cout<<"Stack Elements are \n";
		for(int i = 0;i<=top;i++)
		{
			cout<<Arr[i]<<"\t";
		}
		cout<<"\n";
	}
}

void Stack::Push(int No)
{
	if(top == iSize-1)
	{
		cout<<"Stack is Full\n";
		return;
	}
	else
	{
		top++;
		Arr[top] = No;
	}
}

int Stack::Pop()
{
	if(top == -1)
	{
		cout<<"Stack is empty\n";
		return -1;
	}
	else
	{
		int iNo = Arr[top];
		top--;
		return iNo;
	}
}

int Stack::Count()
{
	return top+1;
}
int main()
{
	int iNo = 0;

	cout<<"Enter the size of array : ";
	cin>>iNo;

	Stack *sobj = new Stack(iNo);

	int iChoice = 1, iValue = 0,iRet = 0;

	while(iChoice != 0)
	{
		cout<<"\nMENU\n\n";
		cout<<"1: Push\n";
		cout<<"2: Pop\n";
		cout<<"3: Display\n";
		cout<<"4: Count\n";
		cout<<"0: Exit\n\n";

		cout<<"Enter your choice : ";
		cin>>iChoice;

		switch(iChoice)
		{
	 
				case 1:
					cout<<"Enter the Element you want to push : ";
					cin>>iValue;
					sobj->Push(iValue);
					break;

				case 2:
					iRet = sobj->Pop();
					cout<<"Poped Element is : "<<iRet<<"\n";
					break;

				case 3:
					sobj->Display();
					break;

				case 4:
					iRet = sobj->Count();
					cout<<"Total Elements Stack are : "<<iRet<<"\n";
					break;

				case 0:
					cout<<"Thank you\n";
					break;

				default:
					cout<<"Enter valid choice\n";
					break;
		}
	}
	return 0;
}