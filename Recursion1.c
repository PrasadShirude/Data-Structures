#include<stdio.h>

int DisplayI(int iNo)
{	
	while(iNo > 0)
	{
		printf("%d\n",iNo);
		iNo--;
	}
}
int DisplayR(int iNo)
{
	if(iNo > 0)
	{
		printf("%d\n",iNo);
		iNo--;
		DisplayR(iNo);
		printf("Hello\n");
	}

}
int main()
{	
	int iNo = 0;

	printf("Enter the number : ");
	scanf("%d",&iNo);
	printf("\n");
	DisplayR(iNo);

	return 0;
}