// Accept N numbers from users and perform addition of N numbers

#include<iostream>
using namespace std;

#define TRUE 1
#define FALSE 0

typedef int BOOL;

class Array
{
private:
	int *Arr;
	int iSize;

public:
	Array(int);
	~Array();
	void Accept();
	void Display();
	int Addition();
	BOOL Check(int);
};

Array::Array(int iNo)
{
	iSize = iNo;
	Arr = new int[iSize];
}

Array::~Array()
{	
	cout<<"Inside Destructor\n";
	delete []Arr;
}

void Array::Accept()
{
	cout<<"Enter the elements\n";
	for(int i = 0;i<iSize;i++)
	{
		cin>>Arr[i];
	}
	cout<<"\n";
}

void Array::Display()
{
	cout<<"Elements of array are \n ";
	for(int i = 0;i<iSize;i++)
	{
		cout<<Arr[i]<<"\t";
	}
	cout<<"\n\n";
}

int Array::Addition()
{
	int iSum = 0;

	for(int i = 0;i<iSize;i++)
	{
		iSum += Arr[i];
	}
	return iSum;
}

BOOL Array::Check(int No)
{
	for(int i = 0;i<iSize;i++)
	{
		if(Arr[i] == No)
		{
			return TRUE;
		}
	}
	return FALSE;
}
int main()
{
	int iNo = 0, iRet = 0, No = 0;
	BOOL bRet = FALSE;

	cout<<"Enter the size of array : ";
	cin>>iNo;

	Array *aobj = new Array(iNo);	// call to Constructor	// Heap
	//Array.aobj(iNo);				// Static allocation which is allocated on stack/ main memory

	aobj->Accept();
	aobj->Display();

	iRet = aobj->Addition();
	cout<<"Addition of all elements is : "<<iRet<<"\n";

	cout<<"Enter the number you want to check : ";
	cin>>No;
	bRet = aobj->Check(No);
	if(bRet == TRUE)
	{
		cout<<"Element is present\n";
	}
	else
	{
		cout<<"Element not found\n";
	}
	delete aobj;		// Call to destructor

	return 0;
}