#include<stdio.h>


void DisplayI()
{
	int i = 0;

	printf("\n");
	//   1   2   3
	for(i=0;i<4;i++)
	{
		printf("*\t");	//4
	}
	printf("\n");

}

void DisplayR()
{
	static int i = 1;	// 1

	if(i<=4)			// 2
	{
		printf("*\n");  // 4
		i++;			// 3
		DisplayR();		// Recursive
	}
}
int main()
{
	DisplayR();

	return 0;
}