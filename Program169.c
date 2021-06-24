// Number is perfect number or not

#include<stdio.h>
#include<stdbool.h>


bool CheckPerfectI(int iNo)
{
	int iSum = 0;
	int iCnt = 1;

	while(iCnt <= iNo/2)
	{
		if((iNo%iCnt) == 0)
		{
			iSum += iCnt;
		}
		iCnt++;
	}

	if(iSum == iNo)
	{
		return true;
	}
	else
	{
		return false;
	}
}  

bool CheckPerfectR(int iNo)
{
	static int iSum = 0;
	static int iCnt = 1;

	if(iCnt <= iNo/2)
	{
		if((iNo%iCnt) == 0)
		{
			iSum += iCnt;
		}
		iCnt++;
		CheckPerfectR(iNo);
	}

	if(iSum == iNo)
	{
		return true;
	}
	else
	{
		return false;
	}
}  
int main()
{	
	int iValue = 0, iRet = 0;
	printf("Enter number : ");
	scanf("%d",&iValue);

	bool bRet = false;
	bRet = CheckPerfectR(iValue);

	if(bRet == true)
	{
		printf("Number is perfect\n");
	}
	else
	{
		printf("Number is not perfect\n");
	}

	return 0;
}