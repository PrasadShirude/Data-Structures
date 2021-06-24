// Calculate length of string

#include<stdio.h>


int StringLenI(char *str)
{
	int iLen = 0;

	while(*str != '\0')
	{
		
		iLen++;
		*str++;
	}
	return iLen;
	
}

int StringLenR(char *str)
{
	static int iLen = 0;

	if(*str != '\0')
	{
		
		iLen++;
		*str++;
		StringLenR(str);
	}
	return iLen;
	
}


int main()
{	
	char arr[100];

	int iRet = 0;
	printf("Enter string : ");
	scanf("%[^'\n']s",&arr);

	iRet = StringLenR(arr);

	printf("Length of string is %d\n",iRet);

	return 0;
}