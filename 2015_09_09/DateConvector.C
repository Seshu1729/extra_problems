/*
	For this program just I used to parse input string 
	and check different conditions to obtain result

	I include validation of given date

	This program is capable to check upto 10000 years
	If we cross that limit it shows a message
*/

#include<stdio.h>
#include<conio.h>
#include<malloc.h>
int stringLength(char input[])
{
	int length=-1;
	while(input[++length]!='\0');
	return length;
}
int isEqual(char original[],char expected[])
{
	int len1,len2,i;
	len1 = stringLength(original);
	len2 = stringLength(expected);
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
void trim(char input[])
{
	if(input[stringLength(input)-1]==' ')
		input[stringLength(input)-1]='\0';
}
int splitDigit(int *value,int val)
{
	int remaining;
	remaining = *value%val;
	*value /= val;
	return remaining;
}
int isLeap(int year)
{
	int leap=1;
	if(year%4!=0)
		leap=0;
	else if(year%400==0)
		leap=1;
	else if(year%100==0)
		leap=0;
	return leap;
}
int isValid(int day,int month,int year)
{
	int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	if(isLeap(year))
		days[1]++;
	if(days[month-1]<day||day<1)
		return 0;
	if(year>10000||month>12||month<0)
		return 0;
	return 1;

}
char *stringConcatination(char input1[],char input2[],char input3[],char input4[])
{
	char *result;
	int l1,l2,l3,l4,index,i;
	l1 = stringLength(input1);
	l2 = stringLength(input2);
	l3 = stringLength(input3);
	l4 = stringLength(input4);
	result = (char *)malloc((l1+l2+l3+l4)*sizeof(char));
	for(index=0,i=0;i<l1;)
		result[index++] = input1[i++];
	for(i=0;i<l2;)
		result[index++] = input2[i++];
	for(i=0;i<l3;)
		result[index++] = input3[i++];
	for(i=0;i<l4;)
		result[index++] = input4[i++];
	result[index] = '\0';
	return result;
}
char *dayparser(int value)
{
	char *numbers[] = {"first ","second ","third ","four",
							"fif","six","seven","eigh",
							"nin","ten","eleven","twel","thirteen"};
	if(value<4)
		return numbers[value-1];
	else if(value<14)
		return stringConcatination(numbers[value-1],"th ","","");
	else if(value<20)
		return stringConcatination(numbers[value-11],"teenth ","","");
	else if(value==20)
		return "twentieth ";
	else if(value<30)
		return stringConcatination("twenty ",dayparser(value%10),"","");
	else if(value==30)
		return "thirtieth ";
	else if(value==31)
		return "thirty first ";
	return "";
}
char *yearparser(int value)
{
	int halfvalue;
	char *numbers[] = {"one","two","three","four",
							"five","six","seven","eight",
							"nine","ten","eleven","twelve",
							"twent","thirt","fourt","fift",
							"sixt","sevent","eight","nint","hundred","thousand"};
	if(value==0)
		return "";
	else if(value<13)						
		return numbers[value-1];
	else if(value<20)
		return stringConcatination(numbers[value],"een","","");
	else if(value%10==0&&value<100)
		return stringConcatination(numbers[(value/10)+10],"y","","");
	else if(value<100)
		return stringConcatination(yearparser((value/10)*10)," ",yearparser(value%10),"");
	else if(value==100)
		return "hundred";
	else if(value<1000)
	{
		halfvalue = splitDigit(&value,100);
		if(halfvalue<10)
			return stringConcatination(numbers[value-1]," hundred ",yearparser(halfvalue),"");
		else
			return stringConcatination(numbers[value-1]," ",yearparser(halfvalue),"");
	}
	else if(value<10000)
	{
		halfvalue = splitDigit(&value,100);
		if(halfvalue<10)
		{
			value = value * 100 + halfvalue;
			halfvalue = splitDigit(&value,1000);
			return stringConcatination(yearparser(value)," thousand ",yearparser(halfvalue),"");
		}
		else
			return stringConcatination(yearparser(value)," ",yearparser(halfvalue),"");
	}
	else if(value==10000)
		return "ten thousand";
	return "";
}
char *DateConvector(char input[])
{
	char *result;
	char *month[] = {"january","february","march","april","may","june","july","august","september","october","november","december"};
	int length,count,index,storage[3]={0,0,0},i;
	length = stringLength(input);
	for(i=0,index=0;i<length;i++)
	{
		while(input[i]!='/'&&input[i]!='\0')
			storage[index] = (storage[index]*10)+input[i++]-48;
		index++;
	}
	if(isValid(storage[0],storage[1],storage[2]))
		result = stringConcatination(dayparser(storage[0]),month[storage[1]-1]," of ",yearparser(storage[2]));
	else if(storage[2]>10000)
		result = "range excided";
	else
		result = "invalid date";
	return result;
}
void inputTestCases()
{
	int i;
	struct testcases
	{
		char *input;
		char *output;
	}test[20] =	{
					{"13/04/1996","thirteenth april of ninteen ninty six"},
					{"14/4/1919","fourteenth april of ninteen ninteen"},
					{"25/12/2008","twenty fifth december of two thousand eight"},
					{"20/10/1601","twentieth october of one thousand six hundred one"},
					{"15/6/110","fifteenth june of one ten"},
					{"2/1/1001","second january of one thousand one"},
					{"10/1/1992","tenth january of ninteen ninty two"},
					{"12/12/1010","twelth december of ten ten"},
					{"14/2/926","fourteenth february of nine twenty six"},
					{"24/3/101","twenty fourth march of one hundred one"},
					{"1/1/1","first january of one"},
					{"1/12/2010","first december of twenty ten"},
					{"14/04/1998","fourteenth april of ninteen ninty eight"},
					{"12/12/10000","twelth december of ten thousand"},
					{"32/1/2015","invalid date"},
					{"29/2/2015","invalid date"},
					{"29/2/2000","twenty ninth february of two thousand"},
					{"29/2/1900","invalid date"},
					{"31/11/1999","invalid date"},
					{"2/12/10001","range excided"}
				};
	char *finalresult;
	for(i=0;i<20;i++)
	{
		finalresult = DateConvector(test[i].input);
		trim(finalresult);
		if(isEqual(finalresult,test[i].output))
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