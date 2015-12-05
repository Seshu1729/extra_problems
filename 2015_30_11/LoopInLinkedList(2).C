#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
	int num;
	struct node *next;
};
struct node *getNode();
struct node *numberToLoopLinkedList(int N,int M);

//Main Algorithm Starts Here

int getResult(struct node *head)
{
	struct node *temp = NULL;
	while (head != NULL)
	{
		if (head->next == NULL)
			return head->num;
		temp = head;
		head = head->next;
		temp->next = NULL;
	}
	return -1;    //Error Condition
}


void testInputCases()
{
	int i;
	struct node *head1 = numberToLoopLinkedList(12346789,9);
	struct node *head2 = numberToLoopLinkedList(123456789,8);
	struct node *head3 = numberToLoopLinkedList(123,1);
	struct node *head4 = numberToLoopLinkedList(1,1);
	struct testcases
	{
		struct node *head;
		int result;
	}test[4] = {
			{ head1, 9 },
			{ head2, 8 },
			{ head3, 1 },
			{ head4, 1 }
	};
	for (i = 0; i<4; i++)
	{
		if (getResult(test[i].head) == test[i].result)
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

struct node *getNode()
{
	struct node *newNode;
	newNode = (struct node *)malloc(sizeof(struct node));
	return newNode;
}

struct node * numberToLoopLinkedList(int N,int M)
{
	struct node *start = NULL, *newNode, *end = NULL, *middleIndex = NULL;
	newNode = getNode();
	newNode->num = N % 10;
	newNode->next = start;
	start = end = newNode;
	if (N % 10 == M)
		middleIndex = newNode;
	N /= 10;
	while (N)
	{
		newNode = getNode();
		newNode->num = N % 10;
		newNode->next = start;
		start = newNode;
		if (N % 10 == M)
			middleIndex = newNode;
		N /= 10;
	}
	end->next = middleIndex;
	return start;
}