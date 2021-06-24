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

void DisplayI(int iRow,int iCol)
{	
	int i = 0;
	while(i < iRow)
	{	
		int k = 0;
		while(k < iCol)
		{
			printf("*\t");
			k++;
		}
		printf("\n");	
		i++;
	}
}	

int main()
{
	int iValue1 = 0,iValue2 = 0;

	printf("Enter number of rows : ");
	scanf("%d",&iValue1);

	printf("Enter number of columns : ");
	scanf("%d",&iValue2);

	DisplayI(iValue1,iValue2);

	return 0;
}