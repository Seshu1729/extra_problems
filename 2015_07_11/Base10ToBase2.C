#include<stdio.h>
#include<conio.h>
int getResult(int base10)
{
	int base2 = 0, count = 1;
	while (base10)
	{
		base2 += count*(base10 % 2);
		base10 /= 2;
		count *= 10;
	}
	return base2;
}
void testInputCases()
{
	int i;
	struct testcases
	{
		int base10;
		int base2;
	}test[3] = {
			{10,1010},
			{1,1},
			{0,0}
	};
	for (i = 0; i<3; i++)
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