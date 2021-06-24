// Accprt r and c from user display *
/*
r = 4
c = 4

*	*	*	*
*	*	*	*
*	*	*	*
*	*	*	*

*/
#include<stdio.h>

void Display(int iCol)
{	
	int k = 0;
	while(k < iCol)
		{
			printf("*\t");
			k++;
		}	
}
void DisplayI(int iRow,int iCol)
{	
	int i = 0;
	while(i < iRow)
	{	
		Display(iCol);
		i++;
		printf("\n");	
	}
}	

void DisplayC(int iCol) // Display / travel cols
{
	static int k = 0;
	if(k < iCol)
	{
		printf("*\t");
		k++;
		DisplayC(iCol);	// recursive call
	}
	k = 0;
}

void DisplayR(int iRow,int iCol) // Display / travel rows
{	
	static int i = 0;
	if(i < iRow)
	{	
		DisplayC(iCol);	// Call to travel columns
		printf("\n");	
		i++;
		DisplayR(iRow,iCol);	// recursive call
	}

}
int main()
{
	int iValue1 = 0,iValue2 = 0;

	printf("Enter number of rows : ");
	scanf("%d",&iValue1);

	printf("Enter number of columns : ");
	scanf("%d",&iValue2);

	DisplayR(iValue1,iValue2);

	return 0;
}
	