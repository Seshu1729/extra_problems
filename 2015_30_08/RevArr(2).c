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
int *getResult(int input[],int size)
{
	int *output,start=0,end=size-1,i,j;
	output = (int *)malloc(size*sizeof(int));
	while((input[start]<input[start+1]||input[end]>input[end-1])&&start<end)
	{
		if(input[start]<input[start+1])
			output[start] = input[start++];
		else
			output[end] = input[end--];
	}
	for(i=start,j=end;i<=end&&j>=start;i++,j--)
		output[i] = input[j];
	return output;
}
void inputTestCases()
{
	int input1[] = {1,2,3,4,5,6},               output1[] = {1,2,3,4,5,6},
		input2[] = {1,2,4,3,5,6},               output2[] = {1,2,3,4,5,6},
		input3[] = {2,5,6,9,8,6,10,11},         output3[] = {2,5,6,6,8,9,10,11},
		input4[] = {-4,3,-1,-2,5,6},            output4[] = {-4,-2,-1,3,5,6},
		input5[] = {1,1,1,1,1,1},               output5[] = {1,1,1,1,1,1},
		input6[] = {10,9,7,4,2,0},              output6[] = {0,2,4,7,9,10},
		input7[] = {-1,-2,-3,-4,-5,-6},         output7[] = {-6,-5,-4,-3,-2,-1},
		input8[] = {200,100},                   output8[] = {100,200},
		input9[] = {1},                         output9[] = {1},
		input10[] = {1,2,4,4,4,6},              output10[] = {1,2,4,4,4,6};
	struct testcases test[10] = {
				{input1,output1,6},
				{input2,output2,6},
				{input3,output3,8},
				{input4,output4,6},
				{input5,output5,6},
				{input6,output6,6},
				{input7,output7,6},
				{input8,output8,2},
				{input9,output9,1},
				{input10,output10,6}
			};
	int i,*output;
	for(i=0;i<10;i++)
	{
		output=getResult(test[i].input,test[i].size);
		if(isEqual(output,test[i].output,test[i].size))
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