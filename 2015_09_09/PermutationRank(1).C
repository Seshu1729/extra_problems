/*
	One of my favarate program!!

	In this Method I used two Arrays 

	One for getting denominator in the condition of repetation occured
	example : 2,3,3,3,2   ::::   (5!)/((2!)*(3!))

	Other one is for store no of chances for replacing with that number

	In next method I try to reduce the inner for loop
*/

#include<stdio.h>
#include<conio.h>
#include<malloc.h>
long int fact(int val)
{
	long int i,result=1;
	for(i=2;i<=val;i++)
		result *= i;
	return result;
}
int getResult(long int input)
{
	int count[10] = {0,0,0,0,0,0,0,0,0,0},noOfChances[10]={0,0,0,0,0,0,0,0,0,0};
	long int result=0,i,repeatition=1,index=0;
	while(input)
	{
		for(i=input%10+1;i<10;i++)
			noOfChances[i]++;
		repeatition *= ++count[input%10];
		result += fact(index) * noOfChances[input%10] / repeatition;
		input /= 10;
		index++;
	}
	printf("%d ",result);
	return result;
}
void inputTestCases()
{
	int i;
	struct testcases
	{
		long int input;
		long int output;
	}test[5] = {
					{6258,12},  //with out repetation
					{666333,19},  //with repetation
					{9,0},  //single digit number
					{100,2}, //includes zero
					{44112233,2430}//some bigger number with repitation
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