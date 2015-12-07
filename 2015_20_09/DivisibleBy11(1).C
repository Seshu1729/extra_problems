/*
	It is general Implementation based on divisiblity rule 11
*/
#include<stdio.h>
#include<conio.h>
int getResult(char input[])
{
	int result=0;
	while(*input)
	{
		result+=*(input++)-48;
		if(*input)
			result-=*(input++)-48;
	}
	if(result%11==1)
		return 'N';
	else
		return 'Y';
}
void inputTestCases()
{
	int i;
	struct TestCases
	{
		char *input;
		char output;
	}test[3]={
				{"1234321",'Y'},
				{"0011",'Y'},
				{"1100",'Y'}
			 };
	for(i=0;i<3;i++)
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

