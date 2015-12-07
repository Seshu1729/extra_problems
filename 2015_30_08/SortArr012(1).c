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
int isValid(int input[],int size)
{
	int i;
	for(i=0;i<size;i++)
		if(input[i]!=0&&input[i]!=1&&input[i]!=2)
			return 0;
	return 1;
}
int *getResult(int input[],int size)
{
	int *output,i,count0,count1,count2=0,sum=0;
	output = (int *)malloc(size*sizeof(int));
	for(i=0;i<size;i++)
	{
		sum += input[i];
		if(input[i]==2)
			count2++;
	}
	count1 = sum-(count2*2);
	count0 = size-count1-count2;
	for(i=0;i<size;i++)
	{
		if(i<count0)
			output[i]=0;
		else if(i<count0+count1)
			output[i]=1;
		else
			output[i]=2;
	}
	return output;
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
	int *finalresult,invalid[1] = {-1};
	for(i=0;i<5;i++)
	{
		if(isValid(test[i].input,test[i].size))
		{
			finalresult = getResult(test[i].input,test[i].size);
			if(isEqual(finalresult,test[i].output,test[i].size))
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