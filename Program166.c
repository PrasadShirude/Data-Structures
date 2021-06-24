// Factors of  digits of number

#include<stdio.h>


void FactorsDigit(int iNo)
{
	int i= 2;

	while(i <= iNo/2)
	{
		if((iNo&i)==0)
		{
			printf("%d\n",i);
		}
		i++;
	}
	
}

void FactorsDigitR(int iNo)
{
	static int iCnt = 2;

	if(iCnt <= iNo/2)
	{
		if(iNo % iCnt == 0)
		{
			printf("%d\t",iCnt);
		}
		iCnt++;
		FactorsDigitR(iNo);
	}
	
}
int main()
{	
	int iValue = 0, iRet = 0;
	printf("Enter number : ");
	scanf("%d",&iValue);

	FactorsDigitR(iValue);

	return 0;
}