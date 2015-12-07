/*
	I perform multipication using shift right and add

	For ADD I use 'xor' and 'and' operations 
	Very similar to method in DLD
*/

#include<stdio.h>
#include<conio.h>
long int ADD(long int augend,long int addend)
{
	long int sum,carry;
	do
	{
		sum = augend^addend;
		carry = augend&addend;
		augend = sum;
		addend = carry<<1;
	}while(addend!=0);
	return sum;  
}
long int CMP(long int value)
{
    value = ~value;
    value = ADD(value,1);
    return value;
}
long int MUL(long int multiplicand,long int multiplier)
{
	long int i,product=0,sign=1;
	if(multiplier<0)
	{
		sign = 0;
		multiplier = CMP(multiplier);
	}
	for(i=0;multiplier!=0;i=ADD(i,1))
	{
		if(multiplier%2)
			product = ADD(product,multiplicand<<i);
		multiplier /= 2;
	}
	if(sign==0)
		product = CMP(product);
	return product;
}
void inputTestCases()
{ 
	struct testcases
	{
		long int multiplicand;
		long int multiplier;
		long int result;
	}test[8] = {
					{0,0,0},  //all zeros
					{50,50,2500},  //both are positives
					{-50,50,-2500},  //first one is negitive
					{50,-50,-2500},  //second one is negitive
					{-50,-50,2500},  //both are negitives
					{-36363,8488,-308649144},  //result is negitive 
					{455575775,0,0},  //result is zero due to first number is zero
					{0,337575,0}  //result is zero due to second number is zero
				};
	long int i,output;
	for(i=0;i<8;i=ADD(i,1))
	{
		output = test[i].multiplicand>test[i].multiplier ? 
			(MUL(test[i].multiplicand,test[i].multiplier)) : (MUL(test[i].multiplier,test[i].multiplicand));
		if(output == test[i].result)
			printf("pass\n");
		else
			printf("fail\n");
	}
}
int main()
{
	inputTestCases();
	getch();
	return 0;
}