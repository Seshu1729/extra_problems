
//more accurate then previous one

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
int getGreatest(char input[],int index)
{
	int i,j,length=inputlen(input);
	for(i=0,j=index+1;;i++,j++)
	{
		if(input[i]==input[j])
			continue;
		if(input[i]=='\0'&&input[j]=='\0')
			return 1; 
		if(input[i]=='+'&&input[j]=='-')
			return 1;
		if(input[j]=='+'&&input[i]=='-')
			return 2;
		if(input[i]!='.'&&input[j]=='.')
			return 1;
		if(input[i]=='.'&&input[j]!='.')
			return 2;
		if(input[i]>input[j])
			return 1;
		if(input[j]>input[i])
			return 2;
	}
	return 1;
}
double stringToNumber(char str[],int start,int end)
{
	double pow10[12] = {10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000,100000000000,1000000000000};
	double sign = 1,afterpoint=0,val,beforepoint=0;
  	int pointstrike,index=start,decimal=0;
  	if(str[index]=='-')
  	{
    	index++;
    	sign = -1;
  	}
  	else if(str[index]=='+')
  		index++;
  	for(pointstrike=0;index!=end;index++)
  	{
    	if(str[index]=='.')
    	{
      		pointstrike = 1; 
      		continue;
    	}
    	val = str[index]-'0';
    	if(pointstrike==0)
    		beforepoint = (beforepoint*10)+val;
    	else if(pointstrike==1)
    	{
    		afterpoint = (afterpoint*10)+val;
    		decimal++;
    	}
  	}
  	return (beforepoint+(afterpoint/pow10[decimal-1]))*sign;
}
void getResult(char input[],double *output)
{
	char *first,*second;
	int index,greatest;
	for(index=0;input[index]!=',';index++);
	first = (char *)malloc(index*sizeof(char));
	second = (char *)malloc((inputlen(input)-index)*sizeof(char));
	greatest=getGreatest(input,index);
	if(input[0]=='-'&&input[index+1]=='-')
	{
		if(greatest==2)
			*output = stringToNumber(input,0,index);
		else if(greatest==1)
			*output = stringToNumber(input,index+1,inputlen(input));
	}
	else
	{
		if(greatest==1)
			*output = stringToNumber(input,0,index);
		else if(greatest==2)
			*output = stringToNumber(input,index+1,inputlen(input));
	}
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
				{"+8575.555,-8575.554",8575.555},
				{"-4646.123456,-4646.123457",-4646.123456},
				{"5343.111111111111,5343.111111111112",5343.111111111112},
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