#include <stdio.h>
#include <conio.h>

void printLast5Lines(FILE *fp)
{
	char  buffer[5][4096];
	int index=0,count;
    while (fgets(buffer[index%5],4096,fp)!=NULL)
         index++;
    count=index%5;
    do
    {
    	printf("%s\n",buffer[index%5]);
    	index++;
    }while(count!=index%5);
}

int main()
{
	FILE *fp;
	fp = fopen("AddTwoLinkedList(2).C","r");
	if(fp==NULL)
		printf("File Not Exist\n");
	else
		printLast5Lines(fp);
	_getch();
	return 0;
}