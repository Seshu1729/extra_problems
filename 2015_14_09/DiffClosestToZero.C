#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#define MAX(a) (2<<(sizeof(a)*8)-2)-1
int mod(int value)
{
    if(value<0)
        return (value*-1);
    return value;
}
void merge(int input[],int beg,int mid,int end)
{
	long int i=beg,j=mid+1,index=beg,temp[1000],k;
	while((i<=mid)&&(j<=end))
	{
		if(input[i]<input[j])
		{
			temp[index]=input[i];
			i++;
		}
		else
		{
			temp[index]=input[j];
			j++;
		}
		index++;
	}
	if(i>mid)
	{
		while(j<=end)
		{
			temp[index]=input[j];
			j++;
			index++;
		}
	}
	else
	{
		while(i<=mid)
		{
			temp[index]=input[i];
			i++;
			index++;
		}
	}
	for(k=beg;k<index;k++)
		input[k]=temp[k];
}
void merge_sort(int input[],int beg,int end)
{
	int mid;
	if(beg<end)
	{
		mid=(beg+end)/2;
		merge_sort(input,beg,mid);
		merge_sort(input,mid+1,end);
		merge(input,beg,mid,end);
	}
}
void getResult(int input[],int beg,int end,int *value1,int *value2)
{
	int i,min = MAX(int);
	merge_sort(input,beg,end);
	for(i=0;i<end-1;i++)
	if(mod(input[i]-input[i+1])<min)
	{
		*value1=input[i];
		*value2=input[i+1];
		min=mod(input[i]-input[i+1]);
	}
}
void inputTestCases()
{
	int i,result1,result2,original,expected;
	int input1[] = {1,2,3,4,5,6,7,8,9,0},
		input2[]  = {-1,-2,-3,-4,-5,-6,-7},
		input3[]  = {6,3,8,-3,-9,-5};
	struct testcases
	{
		int *input;
		int size;
		int number1;
		int number2;
	}test[3] =  {
						{input1,10,1,0},
						{input2,7,-1,-2},
						{input3,6,-5,-3}
				};
	for(i=0;i<3;i++)
	{
		getResult(test[i].input,0,test[i].size-1,&result1,&result2);
		original = mod(result1-result2);
		expected = mod(test[i].number1-test[i].number2);
		if(original==expected)
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