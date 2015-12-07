/*
	It reduces time complexicity in some testcases compare to previous one
	In this method of addition is useful for testcases like "123456789" and "1" 
	because carry is carried out only one time 
	In previous program it has to check for carry even it became zero

	It reduces some space complexicity also because it reused the input1 string array for storing output

	Disadvantage in this method is it has to shift entire array if additional carry is added at left significant bit
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int stringLength(char input[])
{
	int length=-1;
	while(input[++length]!='\0');
	return length;
}
void stringCopy(char target[],char source[],int length)
{
	int i;
	for(i=0;i<=length;i++)
		target[i] = source[i];
}
void stringShiftRight(char input[],int length)
{
	int i;
	for(i=length;i>=0;i--)
		input[i+1]=input[i];
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
void add(char *value1,char value2,int *carry)
{
	int result;
	result=(*value1-48)+(value2-48)+(*carry);
	*carry=result/10;
	*value1=(result%10+48);
}
void adder(char input1[],int length1,char input2[],int length2)
{
	int carry=0,index=0,temp=length1;
	while(length2!=-1)
		add(&input1[length1--],input2[length2--],&carry);
	while(length1!=-1&&carry!=0)
		add(&input1[length1--],48,&carry);
	if(carry!=0)
	{
		stringShiftRight(input1,temp+1);
		input1[0]=carry+48;
	}
}
char *getResult(char input1[],int length1,char input2[],int length2)
{
	if(length1<length2)
	{
		adder(input2,length2,input1,length1);
		return input2;
	}
	else
	{
		adder(input1,length1,input2,length2);
		return input1;
	}
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
	}test[4] = {
						{"123456789","1","123456790"},//which ends carry in middle
						{"45464","88345","133809"},//which has additional carry
						{"45464","7654444","7699908"},//second number is bigger than first
						{"","",""}//empty strings
				};
	for(i=0;i<4;i++)
	{
		length1=stringLength(test[i].input1);
		length2=stringLength(test[i].input2);
		mainInput1=(char *)malloc((length1+1)*sizeof(char));
		stringCopy(mainInput1,test[i].input1,length1);
		mainInput2=(char *)malloc((length2+1)*sizeof(char));
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

