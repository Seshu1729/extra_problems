/*
	It is direct binary to octal convertion

	It has complexity of O(4n/3) including calculating length

	Next method is more efficient then this method

	It can solve in lsser than this method
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
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
char getOctal(char input[],int index1,int index2)
{
	int i,output=0;
	for(i=index1;i<=index2;i++)
	{
		output*=2;
		output+=input[i]-48;
	}
	return output+48;
}
char *getResult(char input[])
{
	char *output;
	int length=stringLength(input),index1=0,index2,index=0;
	output=(char *)malloc(sizeof(char)*(length/3+2));
	index2=length%3;
	if(index2==0)
		index2+=3;
	while(index2<=length)
	{
		output[index]=getOctal(input,index1,index2-1);
		index1=index2;
		index2+=3;
		index++;
	}
	output[index]='\0';
	return output;
}
void testInputCases()
{
	int i;
	char *Input;
	struct testcases
	{
		char *input;
		char *output;
	}test[6] = {
					{"1","1"},  //having one digit
					{"11","3"},  //having two digits
					{"101","5"},  //having three digits
					{"111000","70"},  //length % 3 ==0
					{"1110001","161"},  //length % 3 == 1
					{"01010101","125"}  //length % 3 ==2
				};
	for(i=0;i<6;i++)
	{
		Input=stringManage(test[i].input);
		if(isEqual(getResult(Input),test[i].output))
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