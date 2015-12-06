#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int LCM(int a, int b, int c, int d)
{
	int bigger, i;
	bigger = a > b ? (a > c ? (a>d ? a : d) : (c>d ? c : d)) : (b > c ? (b>d ? b : d) : (c>d ? c : d));
	for (i = bigger;; i += bigger)
	{
		if (i%a == 0 && i%b == 0 && i%c == 0 && i%d == 0)
			return i;
	}
	return 1;
}

//Main Algorithm Starts Here

int getResult(int n1, int n2, int n3, int n4, int k)
{
	int LCM12, LCM13, LCM14, LCM23, LCM24, LCM34, LCM123, LCM124, LCM234, LCM134, LCM1234, result, rem1, rem2, rem3, rem4;
	if (n1<0 || n2<0 || n3<0)
		return -1;         //Error Condition
	LCM12 = LCM(n1, n2, 1, 1);
	LCM13 = LCM(n1, 1, n3, 1);
	LCM14 = LCM(n1, 1, 1, n4);
	LCM23 = LCM(1, n2, n3, 1);
	LCM24 = LCM(1, n2, 1, n4);
	LCM34 = LCM(1, 1, n3, n4);
	LCM123 = LCM(n1, n2, n3, 1);
	LCM124 = LCM(n1, n2, 1, n4);
	LCM234 = LCM(1, n2, n3, n4);
	LCM134 = LCM(n1, 1, n3, n4);
	LCM1234 = LCM(n1, n2, n3, n4);

	result = (k*LCM1234) / ((LCM1234 / n1) + (LCM1234 / n2) + (LCM1234 / n3) + (LCM1234 / n4) - (LCM1234 / LCM12) - (LCM1234 / LCM13) - (LCM1234 / LCM14) - (LCM1234 / LCM23) - (LCM1234 / LCM24) - (LCM1234 / LCM34) + (LCM1234 / LCM123) + (LCM1234 / LCM124) + (LCM1234 / LCM234) + (LCM1234 / LCM134) - 1);  //Main Formula

	if ((result / n1) + (result / n2) + (result / n3) + (result / n4) - (result / LCM12) - (result / LCM13) - (result / LCM14) - (result / LCM23) - (result / LCM24) - (result / LCM34) + (result / LCM123) + (result / LCM124) + (result / LCM234) + (result / LCM134) - (result / LCM1234)<k)
	{
		rem1 = n1 - result%n1;
		rem2 = n2 - result%n2;
		rem3 = n3 - result%n3;
		rem4 = n4 - result%n4;
		return result + (rem1 < rem2 ? (rem1 < rem3 ? (rem1<rem4 ? rem1 : rem4) : (rem3<rem4 ? rem3 : rem4)) : (rem2 < rem3 ? (rem2<rem4 ? rem2 : rem4) : (rem3<rem4 ? rem3 : rem4)));
	}
	else
	{
		rem1 = result%n1;
		rem2 = result%n2;
		rem3 = result%n3;
		rem4 = result%n4;
		return result - (rem1 < rem2 ? (rem1 < rem3 ? (rem1<rem4 ? rem1 : rem4) : (rem3<rem4 ? rem3 : rem4)) : (rem2 < rem3 ? (rem2<rem4 ? rem2 : rem4) : (rem3<rem4 ? rem3 : rem4)));
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
		int n4;
		int k;
		int r;
	}test[6] = {
			{ 3, 4, 6, 10, 25, 48 },
			{ 4, 6, 2, 12, 14, 28 },
			{ 42, 33, 33, 22, 22, 264 },
			{ 22, 22, 28, 33, 44, 476 },
			{ -2, 9, 9, 2, 100, -1 },
			{ 2, -2, 7, 3, 200, -1 }
	};
	for (i = 0; i<6; i++)
	{
		if (getResult(test[i].n1, test[i].n2, test[i].n3,test[i].n4, test[i].k) == test[i].r)
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