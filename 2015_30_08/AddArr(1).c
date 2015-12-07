#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct testcases
{
	int *arr1;
	int *arr2;
	int *output;
	int size1;
	int size2;
	int size3;
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
int getNumber(int arr[],int size)
{
	int i,val=0;
	for(i=size-1;i>=0;i--)
		val=(val*10)+arr[i];
	return val;
}
int *getArray(int arr1[],int number)
{
	int i,digits=0,temp=number,*result;
	while(temp!=0)
	{
		digits++;
		temp /= 10;
	}
	result=(int *)malloc(digits*sizeof(int));
	for(i=0;number;i++)
	{
		result[i] = number%10;
		number /= 10;
	}
	return result;
}
int *getResult(int arr1[],int arr2[],int size1,int size2)
{
	int num1,num2,maxsize;
	num1 = getNumber(arr1,size1);
	num2 = getNumber(arr2,size2);
	return getArray(arr1,num1+num2);
}
void inputTestCases()
{
	int A1[] = {1,2,3},       B1[] = {4,5,6},   output1[] = {5,7,9},  //simple example
		A2[] = {1,2,3},       B2[] = {4,5,7},   output2[] = {5,7,0,1},  //having carry
		A3[] = {1,2},         B3[] = {4,5,6},   output3[] = {5,7,6},  //B has more digits than A
		A4[] = {1,2,3},       B4[] = {4,5},     output4[] = {5,7,3},  //A has more digits than B
		A5[] = {0,0,0},       B5[] = {0,0,0},   output5[] = {0};  //having zeros
	struct testcases test[5] = {
				{A1,B1,output1,3,3,3},
				{A2,B2,output2,3,3,4},
				{A3,B3,output3,2,3,3},
				{A4,B4,output4,3,2,3},
				{A5,B5,output5,3,3,0}
			};
	int i,*result;
	for(i=0;i<5;i++)
	{
		result=getResult(test[i].arr1,test[i].arr2,test[i].size1,test[i].size2);
		if(isEqual(result,test[i].output,test[i].size3))
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