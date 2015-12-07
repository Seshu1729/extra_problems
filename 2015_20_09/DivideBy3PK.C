/*
	This method has time complexity O(1) if k is divisible by 3 or string is empty
	otherwise it takes O(n) where n is length of p
*/
#include<stdio.h>
#include<conio.h>
int isDivisibleBy3(char p[])
{
	int sum=0;
	while(*p)
		sum=(sum+(*p++)-48)%3;
	return sum;
}
char getResult(char p[],int k)
{
	if(k%3==0||p[0]=='\0')
		return 'Y';
	else if(!isDivisibleBy3(p))
		return 'Y';
	else
		return 'N';
}
void inputTestCases()
{
	int i;
	struct testcases
	{
		char *p;
		int k;
		char result;
	}test[6]={
				{"100",3,'Y'},  //k divisible by 3
				{"123123123",5,'Y'}, //k not divisible by 3
				{"6",4,'Y'},  //single digit p
				{"123",0,'Y'},  //k value is zero
				{"",4,'Y'},  //single digit p
				{"001",3,'Y'}  //zeros in p
			 };
	for(i=0;i<6;i++)
	{
		if(getResult(test[i].p,test[i].k)==test[i].result)
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

