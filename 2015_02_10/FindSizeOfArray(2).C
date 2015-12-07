/*
	Here I am using jumpAsc function to jump all ascending order numbers

	For this I am using same function call until getting apt result
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int jumpAsc(int input[],int index)
{
	int pointer=index,label=1;
	while(input[pointer]>input[pointer-1])
	{
		pointer+=label;
		label*=2;
	}
	return pointer/2;
}
int getResult(int input[])
{
	int index=1;
	if(input[1]<input[0])
		return 2;
	while(1)
	{
		if(input[index]>input[index-1]&&input[index+1]<=input[index]&&input[index-2]<input[index-1])
			break;
		index=jumpAsc(input,index);
	}
	return (index+1)*2;
}
void testInputCases()
{
	int i;
	int input1[10]={1,2,3,4,5,3,0,0,0,0};  //general condition
	int input2[6]={-1,0,7,3,0,0};  //having zero in first n+1 elements
	int input3[10]={-1,0,2,5,7,0,0,0,0,0};  // n+2 element is zero
	int input4[12]={-1,1,4,8,9,11,-5,0,0,0,0,0};  // n+2 element is negitive
	int input5[10]={1,3,5,7,9,9,0,0,0,0};  //n+1 and n+2 are equal
	int input6[10]={-5,-4,-3,-2,-1,-1,0,0,0,0};  //n+1 and n+2 are equal and those are negitives
	int input7[10]={-5,-4,-3,-2,0,0,0,0,0,0};  //n+1 and n+2 are equal and those are equal to zero
	int input8[2]={9,1};  //having only two numbers
	struct testcases
	{
		int *input;
		int output;
	}test[8] = {
					{input1,10},
					{input2,6},
					{input3,10},
					{input4,12},
					{input5,10},
					{input6,10},
					{input7,10},
					{input8,2}
				};
	for(i=0;i<8;i++)
	{
		if(getResult(test[i].input)==test[i].output)
			printf("pass\n");
		else
			printf("fail\n");
	}
}
int main()
{
	testInputCases();
	getch();
}