#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int MODULUS(int n)
{
	if (n<0)
		return n*-1;
	return n;
}

int getResult(int *Array, int size, int k, int n)
{
	int i, cost = 0,itemsGet, *countArray, range = n<5 ? 10 - n : n + 1;
	countArray = (int *)malloc(sizeof(int)*range);
	for (i = 0; i<range; i++)
		countArray[i] = 0;
	for (i = 0; i<size; i++)
		countArray[MODULUS(n - Array[i])]++;
	itemsGet = countArray[0];
	for (i = 1; itemsGet < k; i++)
	{
		itemsGet += countArray[i];
		cost += countArray[i] * i;
	}
	if (itemsGet>k)
		cost -= (itemsGet - k)*(i - 1);
	return cost;

}

void testInputCases()
{
	int i;
	int Array1[30] = { 2, 3, 1, 3, 4, 5, 4, 3, 3, 3, 6, 9, 0, 7, 0, 5, 3, 5, 7, 7, 1, 2, 8, 9, 5, 6, 6, 5, 5, 7 };
	int Array2[30] = { 1, 1, 1, 1, 1, 1, 1, 5, 5, 5, 3, 3, 3, 4, 4, 4, 8, 8, 8, 2, 2, 7, 7, 8, 8, 8, 8, 8, 8, 8 };
	int Array3[30] = { 5, 4, 3, 3, 3, 6, 9, 0, 7, 0, 5, 3, 1, 1, 5, 5, 5, 3, 3, 3, 4, 4, 4, 8, 1, 2, 8, 2, 7, 8 };
	struct testcases
	{
		int *Array;
		int size;
		int k;
		int n;
		int result;
	}test[3] = {
			{ Array1, 30, 8, 5, 2 },
			{ Array2, 30, 20, 9, 53 },
			{ Array3, 30, 15, 0, 32 }
	};
	for (i = 0; i<3; i++)
	{
		if (getResult(test[i].Array, test[i].size, test[i].k, test[i].n) == test[i].result)
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