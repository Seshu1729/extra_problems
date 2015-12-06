#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int GCD(int a, int b);

//Main Algorithm Starts Here

int getResult(int n1, int n2, int k)
{
	int LCM, result, rem1, rem2;
	if (n1<0 || n2<0)
		return -1;         //Error Condition
	LCM = (n1*n2) / GCD(n1, n2);

	result = ((k*LCM) / ((LCM / n1) + (LCM / n2) - 1));    //Main Formula

	if ((result / n1) + (result / n2) - (result / LCM) < k)
	{
		rem1 = n1 - result%n1;
		rem2 = n2 - result%n2;
		return result + (rem1 < rem2 ? rem1 : rem2);
	}
	else
	{
		rem1 = result%n1;
		rem2 = result%n2;
		return result - (rem1 < rem2 ? rem1 : rem2);
	}
}

void testInputCases()
{
	int i;
	struct testcases
	{
		int n1;
		int n2;
		int k;
		int r;
	}test[5] = {
			{ 3, 4, 10, 20 },
			{ 42, 33, 22, 420 },
			{ 22, 22, 44, 968 },
			{ -2, 9, 100, -1 },
			{ 2, -2, 200, -1 }
	};
	for (i = 0; i<5; i++)
	{
		if (getResult(test[i].n1, test[i].n2, test[i].k) == test[i].r)
			printf("pass\n");
		else
			printf("fail\n");


	}
}

int main()
{
	testInputCases();
	_getch();
}

int GCD(int a, int b)
{
	if (b%a == 0)
		return a;
	else return GCD(b%a, a);
}