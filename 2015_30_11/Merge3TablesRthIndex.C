#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int LCM(int a, int b, int c)
{
	int bigger, i;
	bigger = a > b ? (a > c ? a : c) : (b > c ? b : c);
	for (i = bigger;; i += bigger)
	{
		if (i%a == 0 && i%b == 0 && i%c == 0)
			return i;
	}
	return 1;
}

//Main Algorithm Starts Here

int getResult(int n1, int n2, int n3, int k)
{
	int LCM12, LCM23, LCM31, LCM123, result, rem1, rem2, rem3;

	if (n1<0 || n2<0 || n3<0)
		return -1;         //Error Condition

	LCM12 = LCM(n1, n2, 1);
	LCM23 = LCM(1, n2, n3);
	LCM31 = LCM(n1, 1, n3);
	LCM123 = LCM(n1, n2, n3);

	result = (k*LCM123) / ((LCM123 / n1) + (LCM123 / n2) + (LCM123 / n3) - (LCM123 / LCM12) - (LCM123 / LCM23) - (LCM123 / LCM31) + 1);  //Main Formula

	if ((result / n1) + (result / n2) + (result / n3) - (result / LCM12) - (result / LCM23) - (result / LCM31) + (result / LCM123) < k)
	{
		rem1 = n1 - result%n1;
		rem2 = n2 - result%n2;
		rem3 = n3 - result%n3;
		return result + (rem1 < rem2 ? (rem1 < rem3 ? rem1 : rem3) : (rem2 < rem3 ? rem2 : rem3));
	}
	else
	{
		rem1 = result%n1;
		rem2 = result%n2;
		rem3 = result%n3;
		return result - (rem1 < rem2 ? (rem1 < rem3 ? rem1 : rem3) : (rem2 < rem3 ? rem2 : rem3));
	}
}

void testInputCases()
{
	int i;
	struct testcases
	{
		int n1;
		int n2;
		int n3;
		int k;
		int r;
	}test[7] = {
			{ 3, 4, 6, 10, 20 },
			{ 4, 6, 2, 12, 24 },
			{ 3, 7, 8, 10, 18 },
			{ 42, 33, 33, 22, 420 },
			{ 22, 22, 28, 44, 560 },
			{ -2, 9, 9, 100, -1 },
			{ 2, -2, 7, 200, -1 }
	};
	for (i = 0; i<7; i++)
	{
		if (getResult(test[i].n1, test[i].n2, test[i].n3, test[i].k) == test[i].r)
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