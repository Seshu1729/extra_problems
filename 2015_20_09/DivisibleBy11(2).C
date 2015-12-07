/*
	Change the method of divisibility rule as per comfort of programming
*/
#include<stdio.h>
#include<conio.h>
int getResult(char input[])
{
	int result=0;
	while(*input)
		result=(result*-1)+(*(input++)-48);
	if(result==0)
		return 'Y';
	else
		return 'N';
}
void inputTestCases()
{
	int i;
	struct TestCases
	{
		char *input;
		char output;
	}test[5]={
				{"1234321",'Y'},
				{"0011",'Y'},
				{"1100",'Y'}
			 };
	for(i=0;i<5;i++)
	{
		if(getResult(test[i].input)==test[i].output)
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

