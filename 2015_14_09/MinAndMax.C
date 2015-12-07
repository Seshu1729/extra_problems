#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#define TestCasesSize 3
#define MAX(a) (2<<(sizeof(a)*8)-2)-1
#define MIN(a) (2<<(sizeof(a)*8)-2)
int getResult(int input[],int size,int *min,int *max)
{
	int i;
	*min=MAX(int);
	*max=MIN(int);
	for(i=0;i<size;i++)
	{
		if(input[i]<*min)
			*min=input[i];
		if(input[i]>*max)
			*max=input[i];
	}
}
void inputTestCases()
{
	int i,minResult,maxResult,size;
	int input1[10] = {1,2,3,4,5,6,7,8,9,0},
		input2[7]  = {-1,-2,-3,-4,-5,-6,-7},
		input3[6]  = {6,3,8,-3,-9,-5};
	struct testcases
	{
		int *input;
		int size;
		int min;
		int max;
	}test[TestCasesSize] =  {
								{input1,10,0,9},
								{input2,7,-7,-1},
								{input3,6,-9,8}
							};
	for(i=0;i<TestCasesSize;i++)
	{
		getResult(test[i].input,test[i].size,&minResult,&maxResult);
		if(test[i].min==minResult&&test[i].max==maxResult)
			printf("pass\n");
		else
			printf("fail\n");
	}
}
int main()
{
	inputTestCases();
	getch();
	return 0;
}