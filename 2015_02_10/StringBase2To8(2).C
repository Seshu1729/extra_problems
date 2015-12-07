/*
	I think this is the best algorithm for this problem

	Main Advantage in this program is, it gets result without calculate length

	In best case time complexity is O(n/3)

	In worst case time complexity is O(2n/3)
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
char *getResult(char input[])
{
	int index=0,pointer=0;
	while(input[pointer]!='\0'&&input[pointer+1]!='\0'&&input[pointer+2]!='\0')
	{
		input[index++]=((input[pointer+2]-48)+(2*(input[pointer+1]-48))+(4*(input[pointer]-48)))+48;
		pointer+=3;
	}
	if(input[pointer]=='\0')
		input[index]='\0';
	else if(input[pointer+1]=='\0')
	{
		input[index]=input[pointer];
		input[index+1]='\0';
		while(index)
		{
			input[index]=input[index]+(2*((input[index-1]-48)%4));
			input[index-1]=(input[index-1]-48)/4+48;
			index--;
		}
	}
	else
	{
		input[index]=input[pointer+1]+(2*(input[pointer]-48));
		input[index+1]='\0';
		while(index)
		{
			input[index]=input[index]+(4*((input[index-1]-48)%2));
			input[index-1]=(input[index-1]-48)/2+48;
			index--;
		}
	}
	return input;
}
void testInputCases()
{
	int i,length;
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