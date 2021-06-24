// Accept n number and return addition of n numbers

#include<stdio.h>
#include<stdlib.h>

int SumDigitI(int *arr,int iSize)
{	
	int iCnt = 0,iSum = 0;
	while(iCnt < iSize)
	{
		iSum = iSum + arr[iCnt];
		iCnt++;
	}

	return iSum;
}

int SumDigitR(int *arr,int iSize)
{	
	 static int iCnt = 0,iSum = 0;
	
	if(iCnt < iSize)
	{
		iSum = iSum + arr[iCnt];
		iCnt++;
		SumDigitR(arr,iSize);
	}
	return iSum;
}

int main()
{
	int iSize = 0;
	int *arr = NULL;

	printf("Enter size of array : ");
	scanf("%d",&iSize);

	arr = (int*)malloc(iSize*sizeof(int));

	int i = 0;
	printf("Enter elements : ");
	while(i < iSize)
	{
		scanf("%d",&arr[i]);
		i++;
	}

	int iRet = 0;

	iRet = SumDigitR(arr,iSize);

	printf("Sum of Digit is %d\n",iRet);
	free(arr);
	return 0;
}