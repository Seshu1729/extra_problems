/*
	I am using dynamic programming methodology to solve yhis problem

	It has complexity of O(length1*length2)

	Using suffix tree it can be solved faster than this method

	I am trying to solve this problem using suffix tree

	With in short time I will send that code also sir
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int index1;
	int index2;
};
char *stringManage(char *input)
{
	char *Input;
	int length=-1,i;
	while(input[++length]!='\0');
	Input=(char *)malloc(sizeof(char)*length);
	for(i=0;i<=length;i++)
		Input[i] = input[i];
	return Input;
}
int stringLength(char input[])
{
	int length=-1;
	while(input[++length]!='\0');
	return length;
}
int isEqual(char original[],char expected[])
{
	while(*original&&*expected)
	{
		if(*original!=*expected)
			return 0;
		original++;
		expected++;
	}
	if(!(*original||*expected))
		return 1;
	else
		return 0;
}
struct node maximum(struct node node1,struct node node2)
{   
	if(node1.index2-node1.index1>node2.index2-node2.index1)
		return node1;
	else 
		return node2;
}
struct node** AllocateMemory(int rows, int cols)
{
    struct node **ReturnArray;
    int i;
    ReturnArray = (struct node **)malloc(sizeof(struct node*)*(rows));
    for(i=0;i<rows;i++)
       *(ReturnArray+i) = (struct node *)malloc(sizeof(struct node)*(cols));
    return ReturnArray;
}
char *getResult(char *input1,char *input2,int length1,int length2)
{
    struct node **table,result;
    int i,j,index;
	char *output;
	table=AllocateMemory(length1+1,length2+1);
	result.index1=-1;
	result.index2=-1;
    for(i=0;i<=length1;i++)
    {
        for(j=0;j<=length2;j++)
        {
            if(i==0||j==0)
			{
				table[i][j].index1=i;
				table[i][j].index2=i;
			}
            else if(input1[i-1]==input2[j-1])
            {
                table[i][j].index1 = table[i-1][j-1].index1;
				table[i][j].index2 = table[i-1][j-1].index2+1;
                result=maximum(result,table[i][j]);
            }
            else 
			{
				table[i][j].index1 = i;
				table[i][j].index2 = i;
			}
        }
    }
	output=(char *)malloc(sizeof(char)*(result.index2-result.index1));
	for(i=result.index1,index=0;i<result.index2;i++)
		output[index++]=input1[i];
	output[index]='\0';
    return output;
}
void testInputCases()
{
	int i;
	char *Input1,*Input2;
	struct testcases
	{
		char *input1;
		char *input2;
		char *output;
	}test[5] = {
					{"saiseshu","seshugsaisss","seshu"},//input2>input1
					{"azqpyzaz","zqpzqpyz","zqpyz"},//input1==input2
					{"i am a good boy","am i good boy"," good boy"},//input1>input2
					{"mmmwmmm","gsffswhshh","w"},//single char matched
					{"qwerty","asdfg",""}//no common substring
				};
	for(i=0;i<5;i++)
	{
		Input1=stringManage(test[i].input1);
		Input2=stringManage(test[i].input2);
		if(isEqual(getResult(Input1,Input2,stringLength(Input1),stringLength(Input2)),test[i].output))
			printf("pass\n");
		else
			printf("fail\n");
	}
}
int main()
{
	testInputCases();
	getch();
	return 0;
}