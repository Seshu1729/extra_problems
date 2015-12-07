#include<stdio.h>
#include<conio.h>
#include<malloc.h>
int getResult(char input[])
{
	int length=-1;
	while(input[++length]!='\0');
	return length;
}
void inputTestCases()
{
	int i;
	struct testcases
	{
		char *input;
		int ExpectedLength;
	}test[5] = 	{
						{"I Am A Good Boy",15},
						{"I Am A\0 Good Boy",6},
						{"1",1},
						{"",0},
						{"\0",0}
				};
	for(i=0;i<5;i++)
	{
		if(getResult(test[i].input)==test[i].ExpectedLength)
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