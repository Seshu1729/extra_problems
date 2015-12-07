#include<stdio.h>
#include<conio.h>
int getResult(int base10)
{
	int baseMinus2 = 0, count = 1;
	while (base10)
	{
		if (!(base10 % 2 == 0))
		{
			baseMinus2 += count;
			base10--;
		}
		base10 /= (-2);
		count *= 10;
	}
	return baseMinus2;
}
void testInputCases()
{
	int i;
	struct testcases
	{
		int base10;
		int base2;
	}test[4] = {
			{ 10, 11110 },
			{ 15, 10011 },
			{ 1, 1 },
			{ 0, 0 }
	};
	for (i = 0; i<4; i++)
	{
		if (getResult(test[i].base10) == test[i].base2)
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