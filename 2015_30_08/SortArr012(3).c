#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct testcases
{
	int *input;
	int *output;
	int size;
};
int isEqual(int original[],int expected[],int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		if(original[i]!=expected[i])
			return 0;
	}
	return 1;
}
void swap(int *val1,int *val2)
{
	int temp;
	temp = *val1;
	*val1 = *val2;
	*val2 = temp;
}
int isValid(int input[],int size)
{
	int i;
	for(i=0;i<size;i++)
		if(input[i]!=0&&input[i]!=1&&input[i]!=2)
			return 0;
	return 1;
}
void getResult(int input[],int size)
{
	int pointer0=0,pointer1=0,pointer2=size-1;
	while(pointer1<pointer2)
	{
		if(input[pointer1]==0)
			swap(&input[pointer0++],&input[pointer1++]);
		else if(input[pointer1]==2)
			swap(&input[pointer1],&input[pointer2--]);
		else
			pointer1++;
	}
}
void inputTestCases()
{
	int input1[] = {0,1,2,2,1,0,2,1,0,1},        output1[] = {0,0,0,1,1,1,1,2,2,2},
		input2[] = {2,2,2,2,1,1,1,1,0,0,0,0},    output2[] = {0,0,0,0,1,1,1,1,2,2,2,2},
		input3[] = {2,1,0,2,1,0,2,1,0},          output3[] = {0,0,0,1,1,1,2,2,2},
		input4[] = {2,1,0},                      output4[] = {0,1,2},
		input5[] = {1,2,3,4,5,6},                output5[] = {-1}; //-1 on error
	struct testcases test[5] = {
				{input1,output1,10},
				{input2,output2,12},
				{input3,output3,9},
				{input4,output4,3},
				{input5,output5,6}
			};
	int i;
	int invalid[1] = {-1};
	for(i=0;i<5;i++)
	{
		if(isValid(test[i].input,test[i].size))
		{
			getResult(test[i].input,test[i].size);
			if(isEqual(test[i].input,test[i].output,test[i].size))
				printf("pass\n");
			else
				printf("fail\n");
		}
		else
		{
			if(isEqual(invalid,test[i].output,1))
				printf("pass\n");
			else
				printf("fail\n");
		}
	}
}
int main()
{
	inputTestCases();
	getch();
	return 0;
}