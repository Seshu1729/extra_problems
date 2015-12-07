#include<stdio.h>
#include<conio.h>
#include<malloc.h>
int stringCompare(char original[],char expected[])
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
char *getResult(char Input[],char SubInput[])
{
	char *InputCopy,*SubInputCopy;
	while(*Input)
	{
		if(*Input==*SubInput)
		{
			InputCopy=Input;
			SubInputCopy=SubInput;
			while(*InputCopy==*SubInputCopy&&*InputCopy&&*SubInputCopy)
			{
				InputCopy++;
				SubInputCopy++;
			}
			if(!*SubInputCopy)
				return "yes";
		}
		Input++;
	}
	return "no";
}
void inputTestCases()
{
	int i;
	char *output;
	struct testcases
	{
		char *Input;
		char *SubInput;
		char *Result;
	}test[5] = 	{
						{"I Am A Good Boy","Good","yes"},
						{"I Am A\0 Good Boy","Boy","no"},
						{"1$$%##((&(&","(&)","no"},
						{"!@#$%^&*()","%^&","yes"},
						{"1","1","yes"}
				};
	for(i=0;i<5;i++)
	{
		output=getResult(test[i].Input,test[i].SubInput);
		if(stringCompare(output,test[i].Result))
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