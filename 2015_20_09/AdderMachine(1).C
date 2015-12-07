/*
	In this method I used to store output string in reverse order later I perform stringReverse

	This method usful for strings having same length

	Disadvantage is memory wastage and some time wastage for some operations

	In next method I resolve some disadvantages of this program
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void swap(char *variable1,char *variable2)
{
	char temparary;
	temparary=*variable1;
	*variable1=*variable2;
	*variable2=temparary;
}
int stringLength(char input[])
{
	int length=-1;
	while(input[++length]!='\0');
	return length;
}
void stringReverse(char input[],int length)
{
	int start=0,end=length-1;
	while(start<end)
		swap(&input[start++],&input[end--]);
}
void stringCopy(char target[],char source[],int length)
{
	int i;
	for(i=0;i<=length;i++)
		target[i] = source[i];
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
char add(char value1,char value2,int *carry)
{
	int result;
	result=(value1-48)+(value2-48)+(*carry);
	*carry=result/10;
	return (result%10+48);
}
char *adder(char input1[],int length1,char input2[],int length2)
{
	int carry=0,index=0;
	char *output;
	output=(char *)malloc(sizeof(char)*(length1+2));
	while(length2!=-1)
		output[index++]=add(input1[length1--],input2[length2--],&carry);
	while(length1!=-1&&carry!=0)
		output[index++]=add(input1[length1--],48,&carry);
	while(length1!=-1)
		output[index++]=input1[length1--];
	if(carry!=0)
		output[index++]=carry+48;
	output[index]='\0';
	stringReverse(output,index);
	return output;
}
char *getResult(char input1[],int length1,char input2[],int length2)
{
	char *output;
	if(length1<length2)
		output=adder(input2,length2,input1,length1);
	else
		output=adder(input1,length1,input2,length2);
	return output;
}
void inputTestCases()
{
	int i,length1,length2;
	char *mainInput1,*mainInput2;
	struct testcases
	{
		char *input1;
		char *input2;
		char *output;
	}test[5] = {
						{"123","123","246"},
						{"45464","7654444","7699908"},
						{"45464","88345","133809"},
						{"0","0","0"},
						{"","",""}
				};
	for(i=0;i<5;i++)
	{
		length1=stringLength(test[i].input1);
		length2=stringLength(test[i].input2);
		mainInput1=(char *)malloc(length1*sizeof(char));
		stringCopy(mainInput1,test[i].input1,length1);
		mainInput2=(char *)malloc(length2*sizeof(char));
		stringCopy(mainInput2,test[i].input2,length2);
		if(isEqual(getResult(mainInput1,length1-1,mainInput2,length2-1),test[i].output))
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