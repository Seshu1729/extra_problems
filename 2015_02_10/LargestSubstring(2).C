/*
	I use Suffix tree to solve the Longest substring problem

	Even it is some what complicated , It's time complexity is relatively low when compared to older method
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	struct node *Children;
	int ChildrenNumber;
	int start;
	int end;
	int path;
};
char *stringManage(char *input1,char extention1,char *input2,char extention2,int length1,int length2)
{
	char *Input;
	int i;
	Input=(char *)malloc(sizeof(char)*(length1+length2+2));
	for(i=0;i<length1;i++)
		Input[i]=input1[i];
	Input[i]=extention1;
	for(i=0;i<length2;i++)
		Input[i+length1+1]=input2[i];
	Input[i+length1+1]=extention2;
	Input[length1+length2+2]='\0';
	return Input;
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
int stringLength(char input[])
{
	int length=-1;
	while(input[++length]!='\0');
	return length;
}
void addSuffix(struct node *root,char input[],int label,int start,int end,int *ResultBeg,int *ResultEnd,int *ResultLen,int path)
{
	int index,found=0,incrementStart,i;
	for(index=0;index<root->ChildrenNumber;index++)
	{
		if(input[root->Children[index].start]==input[start])
		{
			found=1;
			break;
		}
	}
	if(found==1)
	{
		incrementStart=root->Children[index].start;
		while(input[incrementStart]==input[start]&&incrementStart<root->Children[index].end)
		{
			incrementStart++;
			start++;
			label++;
		}
		if(incrementStart<root->Children[index].end)
		{
			addSuffix(&root->Children[index],input,label,incrementStart,root->Children[index].end,ResultBeg,ResultEnd,ResultLen,1);
			root->Children[index].end=incrementStart;
			for(i=0;i<root->Children[index].ChildrenNumber;i++)
				root->Children[index].Children[i].start=incrementStart;
		}
		if(start<end)
			addSuffix(&root->Children[index],input,label,start,end,ResultBeg,ResultEnd,ResultLen,path);
		if(path==2&&root->Children[index].path==1)
		{
			if(*ResultLen<label)
			{
				*ResultBeg=incrementStart-label;
				*ResultEnd=incrementStart;
				*ResultLen=label;
			}
		}
	}
	else
	{
		root->ChildrenNumber++;
		root->Children=(struct node *)realloc(root->Children,(root->ChildrenNumber)*sizeof(struct node));
		root->Children[root->ChildrenNumber-1].Children=NULL;
		root->Children[root->ChildrenNumber-1].ChildrenNumber=0;
		root->Children[root->ChildrenNumber-1].start=start;
		root->Children[root->ChildrenNumber-1].end=end;
		root->Children[root->ChildrenNumber-1].path=path;
	}
}
char *getResult(char input[],int length1,int length2)
{
	struct node root={NULL,0,0,0};
	int i,ResultBeg=0,ResultEnd=0,ResultLen=0;
	char *output;
	for(i=0;i<length1;i++)
		addSuffix(&root,input,0,i,length1,&ResultBeg,&ResultEnd,&ResultLen,1);
	for(i=length1;i<length1+length2;i++)
		addSuffix(&root,input,0,i,length1+length2,&ResultBeg,&ResultEnd,&ResultLen,2);
	output=(char *)malloc((ResultLen+1)*sizeof(char));
	for(i=ResultBeg;i<ResultEnd;i++)
		output[i-ResultBeg]=input[i];
	output[i-ResultBeg]='\0';
	return output;
}
void testInputCases()
{
	int i,length1,length2;
	char *input;
	struct testcases
	{
		char *input1;
		char *input2;
		char *output;
	}test[5] = {
					{"saiseshu","seshugsaisss","seshu"},//input2>input1
					{"azqpyzaz","zqpzqpyz","zqpyz"},//updating the result from zqp to zqpyz
					{"i am a good boy","am i good boy"," good boy"},//input1>input2
					{"mmmwmmm","gsffswhshh","w"},//having chance to getting  result f since input2 has ff as the part
					{"qwerty","asdfg",""}//no common substring
				};
	for(i=0;i<5;i++)
	{
		length1=stringLength(test[i].input1);
		length2=stringLength(test[i].input2);
		input=stringManage(test[i].input1,'#',test[i].input2,'$',length1,length2);
		if(isEqual(getResult(input,length1,length2),test[i].output))
			printf("pass\n");
		else
			printf("fail\n",getResult(input,length1,length2));
	}
}
int main()
{
	testInputCases();
	getch();
	return 0;
}
