#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct student
{
	char *name;
	char *department;
	int section;
	int id;
};
struct testcases
{
	struct student result;
	int id;
};
struct student getResult(struct student details[],int id,int range)
{
	int i;
	for(i=0;i<range;i++)
	{
		if(details[i].id==id)
			return details[i];
	}
}
void inputTestCases()
{
	int i;
	struct student Result;
	char seshu[]="seshu",hemanth[]="hemanth",rajesh[]="rajesh",keerthi[]="keerthi",divya[]="divya";
	char cse[]="cse",mech[]="mech",eee[]="eee",ece[]="ece",civil[]="civil";
	struct student details[5] =  	{
											{seshu,cse,1,528},
											{hemanth,cse,1,428},
											{rajesh,mech,2,353},
											{keerthi,ece,3,222},
											{divya,civil,4,111}
									};
	struct testcases test[4] =		{
											{details[0],528},
											{details[4],111},
											{details[3],222},
											{details[1],428}
									};
	for(i=0;i<4;i++)
	{
		Result=getResult(details,test[i].id,5);
		if(Result.id==test[i].result.id)
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