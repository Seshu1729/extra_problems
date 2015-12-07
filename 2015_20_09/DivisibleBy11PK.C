/*
	This Method takes O(n) where n is length of p
*/
#include<stdio.h>
#include<conio.h>
void getRemainder(char p[],int *remainder,int *length)
{
	while(*p)
	{
		*remainder=(*remainder*-1)+(*(p++)-48);
		*length+=1;
	}
}
char getResult(char p[],int k)
{
	int remainder=0,length=0;
	getRemainder(p,&remainder,&length);
	if(remainder==0)
		return 'Y';
	else if(length%2==0&&k%11==0)
		return 'Y';
	else if(length%2==1&&k%2==0)
		return'Y';
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
	}test[5]={
				{"2334",22,'Y'},
				{"472",10,'Y'},
				{"2992",5,'Y'},
				{"001",5,'N'},
				{"123",3,'N'}
			 };
	for(i=0;i<5;i++)
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

