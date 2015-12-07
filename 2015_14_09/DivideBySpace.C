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
int stringCompare(char *original,char *expected)
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
char *trim(char input[])
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
	}
	return string;
}
int isEqual(char **original,char **expected,int range)
{
	int i;
	for(i=0;i<range;i++)
	{
		if(!stringCompare(original[i],expected[i]))
			return 0;
	}
	return 1;
}
int getNoOfTokens(char *input,char delimitor)
{
	char *temp=input;
	int NoOfTokens=1;
	while(*temp != '\0')
    {
        if(*temp == delimitor)
			NoOfTokens++;
        temp++;
    }
	return NoOfTokens;
}
char **stringDivider(char *input, char delimitor,int NoOfTokens)
{
    int TokenLength=1,index = 0;
    char *temp,*token,**output;
	output = (char**) malloc(sizeof(char*)*NoOfTokens);
    temp = input;
    while(*temp!='\0')
    {
        if(*temp==delimitor)
        {
            (output)[index] = (char*) malloc( sizeof(char)*TokenLength);
            TokenLength = 0;
            index++;
        }
        temp++;
        TokenLength++;
    }
    (output)[index] = (char*)malloc(sizeof(char)*TokenLength);
    index = 0;
    temp = input;
    token = ((output)[index]);
    while(*temp!='\0')
    {
        if(*temp!=delimitor)
        {
            *token = *temp;
            token++;
        }
        else
        {
            index++;
            *token = '\0';
            token = ((output)[index]);
        }
        temp++;
    }
	*token = '\0';
	return output;
}
void inputTestCases()
{
	int i,j,NoOfTokens;
	char **output,*trimedInput;
	char *output1[]={"please","save","trees"},
		 *output2[]={"singleWord"},
		 *output3[]={"1","1","1","1","1","1","1","1","1","1"},
		 *output4[]={"backslah","in","the"},
		 *output5[]={"123","123"};
	struct testcases
	{
		char *input;
		char **ExpectedOutput;
	}test[5] = 	{
					{"please save trees",output1},
					{"   singleWord   ",output2},
					{"1 1 1 1 1 1 1 1 1 1",output3},
					{"backslah in the \0 middle",output4},
					{"          123     123           ",output5}
				};
	for(i=0;i<5;i++)
	{
		output=NULL;
		trimedInput=trim(test[i].input);
		NoOfTokens=getNoOfTokens(trimedInput,' ');
		output=stringDivider(trimedInput,' ',NoOfTokens);
		if(isEqual(output,test[i].ExpectedOutput,NoOfTokens))
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