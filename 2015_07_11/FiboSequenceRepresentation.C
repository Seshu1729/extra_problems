#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int isEqual(char original[], char expected[])
{
	while (*original&&*expected)
	{
		if (*original != *expected)
			return 0;
		original++;
		expected++;
	}
	if (!(*original || *expected))
		return 1;
	else
		return 0;
}

char *getResult(int base10)
{
	int a = 1, b = 1,sum=0,index=1;
	char *baseFib,*result;
	baseFib = (char *)malloc(1);
	result = baseFib;
	while (sum < base10)
	{
		result = (char *)realloc(result,index+1);
		index++;
		*baseFib = '1';
		baseFib++;
		sum += a;
		b = a + b;
		a = b - a;
	}
	*baseFib = '\0';
	baseFib -= 2;
	sum -= base10;
	b = b-a;
	a = a-b;
	while(sum)
	{
		if(a<=sum)
		{
			*baseFib = '0';
			sum -=a;
		}
		baseFib--;
		a = b-a;
		b = b-a;
	}
	return result;
}

void testInputCases()
{
	int i;
	struct testcases
	{
		int base10;
		char *baseFib;
	}test[3] = {
			{ 3, "101" },
			{ 56, "111010101" },
			{ 88, "111111111" }
	};
	for (i = 0; i<3; i++)
	{
		if (isEqual(getResult(test[i].base10),test[i].baseFib))
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