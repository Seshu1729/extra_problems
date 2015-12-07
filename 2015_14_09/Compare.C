#include<stdio.h>
#include<conio.h>
#include<malloc.h>
int stringLength(char input[])
{
	int length=-1;
	while(input[++length]!='\0');
	return length;
}
int isEqual(char *original,char *expected)
{
	while(*original&&*expected)
	{
		if(*original!=*expected)
			return 0;
		original++;
		expected++;
	}
	return 1;
}
char *getResult(char *original,char *expected)
{
	while(*original&&*expected)
	{
		if(*original!=*expected)
			return "no";
		original++;
		expected++;
	}
	if(!(*original||*expected))
		return "yes";
	else
		return "no";
}
void inputTestCases()
{
	int i;
	char *output;
	struct testcases
	{
		char *input1;
		char *input2;
		char *output;
	}test[4] = 	{
						{"I Am A Good Boy","I Am A Good Boy","yes"},
						{"I Am A Good Boy","I Am A God Boy","no"},
						{"","","yes"},
						{"1000","1","no"}          // this is the testcase that gives wrong output in pevious program
				};
	for(i=0;i<4;i++)
	{
		output=getResult(test[i].input1,test[i].input2);
		if(isEqual(output,test[i].output))
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