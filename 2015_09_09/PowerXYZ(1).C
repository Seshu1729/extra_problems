/*
	In this method I use recursion to calculate result

	I think this not apt for large numbers
	
	I think next method is better than this method
*/
#include<stdio.h>
#include<conio.h>
long int getResult(long int x,long int y,long int z)
{
	if(y==0)
		return 1;
	else if(y==1)
		return x%z;
	else if(y%2==1)
		return (x*getResult(x,y-1,z))%z;
	else
		return getResult(x*x,y/2,z)%z;
}
void inputTestCases()
{ 
	struct testcases
	{
		long int X;
		long int Y;
		long int Z;
		long int result;
	}test[4] = {
					{8,11,3,2},  //normal condition
					{0,3,4,0},  //x value is 0
					{2,0,4,1},  //y value is 0
					{6,3,4,0},  //x,z having commmon multiple hence result is 0
				};
	int i;
	for(i=0;i<4;i++)
	{
		if(getResult(test[i].X,test[i].Y,test[i].Z)==test[i].result)
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