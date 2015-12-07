#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct testcases
{
	char *input1;
	char *input2;
	char *output;
};
int inputlen(char input[])
{
	int length=-1;
	while(input[++length]!='\0');
	return length;
}
void stringCopy(char target[],char source[])
{
	int i,len=inputlen(source);
	for(i=0;i<=len;i++)
		target[i] = source[i];
}
int power(int base,int expo)
{
	int ret=1;
	while(expo!=0)
	{
		ret *= base;
		expo--;
	}
	return ret;
}
void trimString(char input[])
{
	int count=0,i;
	for(i=0;input[i]!='\0';i++)
	{
		if(input[i]!=' ')
			input[count++] = input[i];
	}
	input[count]='\0';
}
int isValid(char input[])
{
	int i,len=inputlen(input);
	for(i=0;i<len;i++)
		if(input[i]!='1'&&input[i]!='0')
			return 0;
	return 1;
}
int isEqual(char original[],char expected[])
{
	int len1,len2,i;
	len1 = inputlen(original);
	len2 = inputlen(expected);
	if(len1!=len2)
		return 0;
	else
	{
		for(i=0;i<len1;i++)
		{
			if(original[i]!=expected[i])
				return 0;
		}
	}
	return 1;
}
void stringToNumber(char input1[],char input2[],int *number1,int *number2)
{
	int i;
	for(i=0;i<inputlen(input1);i++)
	{
		*number1 += input1[i] - 48; 
		*number1 *= 10;
	}
	for(i=0;i<inputlen(input2);i++)
	{
		*number2 += input2[i] - 48; 
		*number2 *= 10;
	}
	*number1 /= 10;
	*number2 /= 10;
}
void performAddition(int number1,int number2,int *result)
{
	int carry=0;
	while(number1!=0||number2!=0)
	{
		*result += ((number1%10)+(number2%10)+carry)%2+1;
		carry = (number1%10+number2%10+carry)/2;
		*result *=10;
		number1 /=10;
		number2 /=10;
	}
	if(carry!=0)
		*result += carry+1;
	else
		*result /=10;
}
void makeResultReverse(int *result)
{
	int reverse=0;
	while(*result!=0)
	{
		reverse *= 10;
		reverse += (*result%10);
		*result /= 10;
	}
	*result = reverse;
}
void makeResultBinary(int *result)
{
	int i=0,temp = *result;
	while(temp!=0)
	{
		*result -= power(10,i);
		i++;
		temp /= 10;
	}
}
char *numberToString(int result)
{
	int len=0,temp = result,i;
	char *finalresult;
	while(temp!=0)
	{
		temp /= 10;
		len++;
	}
	if(len!=0)
	{
		finalresult = (char *)malloc((len+1)*sizeof(char));
		for(i=len-1;i>=0;i--)
		{
			finalresult[i] = (result % 10) + 48;
			result /= 10;
		}
		finalresult[len] = '\0';
	}
	else
	{
		finalresult = (char *)malloc(2*sizeof(char));
		finalresult = "0";
	}
	return finalresult;
}
char *getResult(char input1[],char input2[])
{
	int number1=0,number2=0,result=0;
	char *finalresult="error";
	trimString(input1);
	trimString(input2);
	if(isValid(input1)&&isValid(input2))
	{
		stringToNumber(input1,input2,&number1,&number2);
		performAddition(number1,number2,&result);
		makeResultReverse(&result);
		makeResultBinary(&result);
		finalresult = numberToString(result);
	}
	return finalresult;
}
void inputTestCases()
{
	int i;
	struct testcases test[12] = {
				{"1010","0101","1111"},
				{"0000","0000","0"},
				{"1111 1111","i111 1111","error"},
				{"0 0 0 0 0 0 0 0 0","0 0 1 1","1 1"},
				{"11 00","00 11","11 11"},
				{"","   111   ","111"},
				{"1111 1111","","11 1111 11"},
				{"11 11","1+ 11","error"},
				{"1 0 101","1 01","1 1 010"},
				{"1","1","1 0"},
				{" 0 "," 1 "," 1 "},
				{"","","0"}
			};
	char *finalresult,*myinput1,*myinput2,*myoutput;
	for(i=0;i<12;i++)
	{
		myinput1 = (char *)malloc(inputlen(test[i].input1)*sizeof(char));
		myinput2 = (char *)malloc(inputlen(test[i].input2)*sizeof(char));
		myoutput = (char *)malloc(inputlen(test[i].output)*sizeof(char));
		stringCopy(myinput1,test[i].input1);
		stringCopy(myinput2,test[i].input2);
		stringCopy(myoutput,test[i].output);
		trimString(myoutput);
		finalresult = getResult(myinput1,myinput2);
		if(isEqual(finalresult,myoutput))
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