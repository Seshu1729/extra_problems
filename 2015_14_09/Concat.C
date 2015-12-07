#include<stdio.h>
#include<conio.h>
#include<malloc.h>
int stringLength(char input[])
{
	int length=-1;
	while(input[++length]!='\0');
	return length;
}
int stringCompare(char *original,char *expected)
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
char *getResult(char input1[],char input2[])
{
	char *output,*temp;
	int length1,length2;
	length1=stringLength(input1);
	length2=stringLength(input2);
	if(length1+length2>0)
		output=(char *)malloc(sizeof(char)*(length1+length2-1));
	else
		output=(char *)malloc(sizeof(char)*(0));
	temp=output;
	while(*input1)
	{
		*output=*input1;
		output++;
		input1++;
	}
	while(*input2)
	{
		*output=*input2;
		output++;
		input2++;
	}
	*output='\0';
	return temp;
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
	}test[5] = 	{
						{"I Am A"," Good Boy","I Am A Good Boy"},
						{"I Am A\0 Good Boy"," Good Boy","I Am A Good Boy"},
						{"10","","10"},
						{"","123","123"},
						{"","",""}
				};
	for(i=0;i<5;i++)
	{
		output=getResult(test[i].input1,test[i].input2);
		if(stringCompare(output,test[i].output))
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