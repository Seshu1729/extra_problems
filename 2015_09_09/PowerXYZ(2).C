/*
	I feel it is better to do some changes in the previous program

	It reduces some function calls than previous one
*/

#include<stdio.h>
#include<conio.h>
long long int getResult(long long int x,long long int y,long long int z)
{
	if(y==0||x==1)
		return 1;
	else if(x>z)
		return getResult(x%z,y,z);
	else if(x<z)
	{
		if(y%2==1)
			return (x*getResult(x*x,y/2,z))%z;
		else
			return (getResult(x*x,y/2,z))%z;
	}
	return 0;
}
void inputTestCases()
{ 
	struct testcases
	{
		long long int X;
		long long int Y;
		long long int Z;
		long long int result;
	}test[5] = {
					{8,11,3,2},  //normal condition
					{0,3,4,0},  //x value is 0
					{2,0,4,1},  //y value is 0
					{6,3,4,0},  //x,z having commmon multiple hence result is 0
					{57577,585,58858,43331},  //some bigger numbers
				};
	int i;
	for(i=0;i<5;i++)
	{
		if(getResult(test[i].X,test[i].Y,test[i].Z)==test[i].result)
			printf("pass\n");
		else
			printf("%ld fail\n",getResult(test[i].X,test[i].Y,test[i].Z));
	}
}
int main()
{
	inputTestCases();
	getch();
	return 0;
}