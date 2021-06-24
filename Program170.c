// Accept number and count bits of are one

#include<stdio.h>


int CountOnBitI(int iNo)
{
	int iMask = 1, iCnt = 0;
	int i = 0;
	while(i < 32)
	{
		if((iNo & iMask) == iMask)
		{
			iCnt++;
		}
		i++;
		iMask = iMask << 1;
	}
	return iCnt;
}

int CountOnBitR(int iNo)
{
	static int iMask = 1, iCnt = 0,i = 0;
	if(i < 32)
	{
		if((iNo & iMask) == iMask)
		{
			iCnt++;
		}
		i++;
		iMask = iMask << 1;
		CountOnBitR(iNo);
	}
	return iCnt;
}
int main()
{
	int iValue = 0, iRet = 0;

	printf("Enter number : ");
	scanf("%d",&iValue);

	iRet = CountOnBitR(iValue);

	printf("Total on bits in %d are %d\n",iValue,iRet);

	return 0;
}