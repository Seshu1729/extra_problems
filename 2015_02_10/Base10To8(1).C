/*
	Hope this is the best method for this program

	It takes time complexity of O(n) where n is number of digits
*/
#include<stdio.h>
#include<conio.h>
int getResult(int base10)
{
	int base8=0,count=1;
	while(base10)
	{
		base8+=count*(base10%8);
		base10/=8;
		count*=10;
	}
	return base8;
}
void testInputCases()
{
	int i;
	struct testcases
	{
		int base10;
		int base8;
	}test[6] = {
					{8,10},  //exactly 8
					{7,7},  //below 8
					{-8,-10},  //negitive 
					{0,0},  //zero
					{283,433},  //some bigger positive
					{-100,-144}  //some smaller negitive
				};
	for(i=0;i<6;i++)
	{
		if(getResult(test[i].base10)==test[i].base8)
			printf("pass\n");
		else
			printf("fail\n");
	}
}
int main()
{
	testInputCases();
	getch();
}