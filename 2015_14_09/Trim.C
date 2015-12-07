#include<stdio.h>
#include<conio.h>
#include<malloc.h>
int stringLength(char input[])
{
	int length=-1;
	while(input[++length]!='\0');
	return length;
}
void stringCopy(char target[],char source[])
{
	int i,len=stringLength(source);
	for(i=0;i<=len;i++)
		target[i] = source[i];
}
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
char *getResult(char input[])
{
	int count=0,i,len;
	char *string;
	string=(char *)malloc(sizeof(char)*stringLength(input));
	stringCopy(string,input);
	for(i=0;input[i]!='\0';i++)
	{
		if((string[i]!=' ')||(string[i]==' '&&string[i+1]!=' '))
			string[count++] = string[i];
	}
	string[count]='\0';
	if(string[0]==' ')
	{
		i=0;
		len=stringLength(string);
		while(i!=len)
			string[i++]=string[i+1];
		if(string[len-2]==' ')
			string[len-2]='\0';
	}
	return string;
}
void inputTestCases()
{
	int i;
	char *output;
	struct testcases
	{
		char *input;
		char *output;
	}test[5] = 	{
						{"I   Am   A    Good      Boy","I Am A Good Boy"},
						{"I    Am    A\0 Good Boy","I Am A"},
						{"1            0","1 0"},
						{"",""},
						{"            1000            ","1000"}
				};
	for(i=0;i<5;i++)
	{
		output=getResult(test[i].input);
		puts(output);
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