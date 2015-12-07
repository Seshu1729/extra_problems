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
	int *array1,product,i;
	array1 = (int *)malloc(size*sizeof(int));
	if(size!=1)
		array1[0] = 1;
	else
		array1[0] = 0;
	product = input[0];
	for(i=1;i<size;i++)
	{
		array1[i] = product;
		product *= input[i]; 
	}
	product = input[size-1];
	for(i=size-2;i>=0;i--)
	{
		array1[i] *= product;
		product *= input[i];
	}
	return array1;
}
void inputTestCases()
{
	int input1[] = {1,2,3,4,5},       output1[] = {120,60,40,30,24},
		input2[] = {1,2,0,3,4},       output2[] = {0,0,24,0,0},
		input3[] = {0,1,2,3,0},       output3[] = {0,0,0,0,0},
		input4[] = {-1,-2,-3,-4,-5},  output4[] = {120,60,40,30,24},
		input5[] = {-1,-2,-3,-4},     output5[] = {-24,-12,-8,-6},
		input6[] = {1},               output6[] = {0},
		input7[] = {1,2},             output7[] = {2,1},
		input8[] = {-1,2,-3,4},       output8[] = {-24,12,-8,6},
		input9[] = {1,-2,3,-4},       output9[] = {24,-12,8,-6},
		input10[] = {0,0,0,0},        output10[] = {0,0,0,0};
	struct testcases test[10] = {
				{input1,output1,5},
				{input2,output2,5},
				{input3,output3,5},
				{input4,output4,5},
				{input5,output5,4},
				{input6,output6,1},
				{input7,output7,2},
				{input8,output8,4},
				{input9,output9,4},
				{input10,output10,4}
			};
	int i;
	int *finalresult;
	for(i=0;i<10;i++)
	{
		finalresult = getResult(test[i].input,test[i].size);
		if(isEqual(finalresult,test[i].output,test[i].size))
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