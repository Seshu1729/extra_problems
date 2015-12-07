#include<stdio.h>
#include<conio.h>
#include<malloc.h>
int inputlen(char input[])
{
	int length=-1;
	while(input[++length]!='\0');
	return length;
}
unsigned long long int getResult(char input[],int size)
{
	unsigned long long int result=0,i,j;
	for(i=size-1,j=0;j<size;i--,j++)
		if(input[i]=='1')
			result += (2<<(j-1));
	if(input[size-1]=='1')
		result += 1;
	return result;
}
void inputTestCases()
{
	struct testcases
	{
		char *input;
		unsigned long long int output;
	};
	struct testcases test[10] = {
				{"00000000001",1},
				{"00000000000",0},
				{"11111",31},
				{"1010",10},
				{"0",0},
				{"0000000000000000000000000000000000000000000000000000000000000000",0},
				{"000000000000000000000000000000000001",1},
				{"1000000000000000000000000000000000000000000000000000000000000000",18446744071562067968},
				{"111111111111111111111111111111111",18446744073709551615},
				{"10101010101010101010101010101010101010101",1431656105}
			};
	unsigned long long int i,finalresult;
	for(i=0;i<10;i++)
	{
		finalresult = getResult(test[i].input,inputlen(test[i].input));
		if(finalresult==test[i].output)
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