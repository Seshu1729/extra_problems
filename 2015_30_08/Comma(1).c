#include<stdio.h>
#include<conio.h>
#include<malloc.h>
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
int isValid(char input[],int length)
{
	int commaCount=0,sign=0,i;
	for(i=0;i<length;i++)
	{
		if(input[i]==',')
		{
			commaCount++;
			if(commaCount==2)
				return 0;
			if(i==0)
				return 0;
		}
		if(input[i]=='+'||input[i]=='-')
		{
			sign++;
			if(sign>2)
				return 0;
		}
		if(!((input[i]>='0'&&input[i]<='9')||input[i]=='-'||input[i]=='+'||input[i]=='.'||input[i]==','))
			return 0;
	}
	if(commaCount!=1)
		return 0;
	return 1;
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
void stringSeperate(char input[],char first[],char second[],int index)
{
	int i,j,length=inputlen(input);
	for(i=0;i<index;i++)
		first[i] = input[i];
	first[i++] = '\0';
	for(j=0;j<length-index;j++,i++)
		second[j] = input[i];
	second[j-1] = '\0';
}
double stringToNumber(char s[])
{
	double ret = 0,sign = 1;
  	int pointstrike,val,index=0;
  	if(s[index]=='-')
  	{
    	index++;
    	sign = -1;
  	}
  	else if(s[index]=='+')
  		index++;
  	for(pointstrike=0;s[index]!='\0';index++)
  	{
    	if(s[index]=='.')
    	{
      		pointstrike = 1; 
      		continue;
    	}
    	val = s[index]-'0';
    	if(val>=0&&val<=9)
    	{
      		if(pointstrike) 
      			sign /= 10.0f;
      		ret = ret*10.0f+(double)val;
    	}
  	}
  	return ret * sign;
}
void getResult(char input[],double *output)
{
	char *first,*second;
	int index;
	double number1,number2;
	for(index=0;input[index]!=',';index++);
	first = (char *)malloc(index*sizeof(char));
	second = (char *)malloc((inputlen(input)-index)*sizeof(char));
	stringSeperate(input,first,second,index);
	number1=stringToNumber(first);
	number2=stringToNumber(second);
	if(number1>number2)
		*output = number1;
	else
		*output = number2;
}
void inputTestCases()
{
	int i;
	double output;
	char *myinput;	
	struct testcases
	{
		char *input;
		double output;
	};
	struct testcases test[12] = {
				{"123,321",321},
				{"-123,-321",-123},
				{" 9 9 9 9 9 , 9 9 9 9 8 ",99999},
				{" +456 . 5, -456 . 6",456.5},
				{"-456.5,-456.6",-456.5},
				{"+8575.55,-8575.54",8575.55},
				{"-4646.666,-4646.667",-4646.666},
				{"5343.666,5343.667",5343.667},
				{"464646",-1},     //-1 means error
				{"767,768,769",-1},     //-1 means error
				{"abc,def",-1},     //-1 means error
				{"+123,+-123",-1}     //-1 means error
			};
	for(i=0;i<12;i++)
	{
		output=-1;
		myinput = (char *)malloc(inputlen(test[i].input)*sizeof(char));
		stringCopy(myinput,test[i].input);
		trimString(myinput);
		if(isValid(myinput,inputlen(myinput)))
			getResult(myinput,&output);
		if(output==test[i].output)
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