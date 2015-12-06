#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MIN(a) (2<<(sizeof(a)*8)-2)

//Main Algorithm Starts Here

int getResult(int *Array, int length)
{
	int *countArray, sum = 0, result = MIN(int), i, j;
	countArray = (int *)malloc(sizeof(int)*length);
	for (i = 0; i<length; i++)
	{
		countArray[i] = sum + Array[i];
		sum += Array[i];
		if (countArray[i]>result)
			result = countArray[i];
	}
	for (i = 1; i<length; i++)
	{
		for (j = i + 1; j<length; j++)
		{
			if (countArray[j] - countArray[i - 1]>result)
				result = countArray[j] - countArray[i - 1];
		}
	}
	return result;
}

void testInputCases()
{
	int i;
	int Array1[10] = {2,-4,1,2,3,-5,0,6,-2,1};
	int Array2[10] = {2,-2,4,6,5,6,8,12,-22,14};
	int Array3[10] = {1,2,3,4,5,6,7,8,9,0};
	struct testcases
	{
		int *Array;
		int size;
		int result;
	}test[3] = {
			{ Array1, 10, 7 },
			{ Array2, 10, 41 },
			{ Array3, 10, 45 }
	};
	for (i = 0; i<3; i++)
	{
		if (getResult(test[i].Array, test[i].size) == test[i].result)
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