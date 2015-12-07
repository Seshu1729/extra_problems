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
void swap(char *val1,char *val2)
{
	char temp;
	temp = *val1;
	*val1 = *val2;
	*val2 = temp;
}
void reverse(char result[],int len)
{
	int i,j;
	for(i=0,j=len-1;i<j;i++,j--)
		swap(&result[i],&result[j]);
}
char *NBitBinaryAdder(char input1[],char input2[])
{
	int carry=0,length1,length2,sum,max,i,j,k;
	char *result;
	length1 = inputlen(input1);
	length2 = inputlen(input2);
	max = length1>length2?length1:length2;
	result = (char *)malloc((max+2)*sizeof(char));
	for(i=length1-1,j=length2-1,k=0;i!=-1&&j!=-1;i--,j--,k++)
	{
		if(carry+(input1[i]-48)+(input2[j]-48)>1)
		{
			if(carry+(input1[i]-48)+(input2[j]-48)==2)
				sum=0;
			else
				sum=1;
			carry=1;
		}
		else
		{
			if(carry+(input1[i]-48)+(input2[j]-48)==1)
				sum=1;
			else
				sum=0;
			carry=0;
		}
		result[k]=sum+48;
	}
	if(i!=-1||j!=-1)
	{
		if(i!=-1)
		{
			while(i!=-1)
			{
				if(carry==0)
					result[k] = input1[i];
				else
				{
					if(input1[i]+carry-48>1)
					{
						if(input1[i]+carry-48==2)
							result[k] = 0+48;
						else
							result[k] = 1+48;
						carry=1;
					}
					else
					{
						if(input1[i]+carry-48==1)
							result[k] = 1+48;
						else
							result[k] = 0+48;
						carry=0;
					}
				}
				i--;
				k++;
			}
		}
		else if(j!=-1)
		{
			while(j!=-1)
			{
				if(carry==0)
					result[k] = input2[j];
				else
				{
					if(input2[j]+carry-48>1)
					{
						if(input2[j]+carry-48==2)
							result[k] = 0+48;
						else
							result[k] = 1+48;
						carry=1;
					}
					else
					{
						if(input2[j]+carry-48==1)
							result[k] = 1+48;
						else
							result[k] = 0+48;
						carry=0;
					}
				}
				j--;
				k++;
			}
		}
	}
	if(carry==1)
	{
		result[k]='1';
		result[k+1]='\0';
	}
	else
		result[k]='\0';
	return result;
}
char *getResult(char input1[],char input2[])
{
	char *result="error";
	trimString(input1);
	trimString(input2);
	if(isValid(input1)&&isValid(input2))
	{
		result=NBitBinaryAdder(input1,input2);
		reverse(result,inputlen(result));
	}
	return result;
}
void inputTestCases()
{
	int i;
	struct testcases test[12] = {
				{"1010","0101","1111"},
				{"0000","0000","0000"},
				{"1111 1111","i111 1111","error"},
				{"0 0 0 0 0 0 0 0 0","0 0 1 1","0 0 0 0 0 0 0 1 1"},
				{"11 00","00 11","11 11"},
				{"","   111   ","111"},
				{"1111 1111","","11 1111 11"},
				{"11 11","1+ 11","error"},
				{"1 0 101","1 01","1 1 010"},
				{"1","1","1 0"},
				{" 0 "," 1 "," 1 "},
				{"","",""}
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