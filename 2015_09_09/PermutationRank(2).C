/*
	I reduce the inner loop that used in previous program

	But I have to use data structure that is combination of matrix of size 3x3 and array of size 3

	I have to update the values in both matrix and array to get result
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
long int getResult(long int input)
{
	int count[10] = {0,0,0,0,0,0,0,0,0,0},matrix[3][3]={0,0,0,0,0,0,0,0,0},inc[4]={0,0,0,0},digit;
	long int result=0,i,repeatition=1,index=0;
	while(input)
	{
		digit = input%10;
		if(digit>=0&&digit<=6)
			inc[2]++;
		if(digit>=0&&digit<=3)
			inc[1]++;
		if(digit==0)
			inc[0]++;
		if(digit==1||digit==4||digit==7)
			matrix[(digit-1)/3][2]++;
		if(digit==0||digit==3||digit==6)
			matrix[digit/3][0]--;
		repeatition *= ++count[input%10];
		if(digit!=9)
			result += fact(index) * (matrix[digit/3][digit%3]+inc[digit/3]) / repeatition;
		else
			result += fact(index) * index / repeatition;
		input /= 10;
		index++;
	}
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