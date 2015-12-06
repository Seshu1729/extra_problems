#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
	int num;
	struct node *next;
};
struct node *getNode();
struct node *numberToLoopLinkedList(int N, int M);

//Main Algorithm Starts Here

int getResult(struct node *head)
{
	struct node  *temp1 = NULL, *temp2 = NULL, *storeNext = NULL;
	int noOfLinks = -1, minNumberOfNodes, count = 0, loopCount = -1, resultIndex;
	while (head != NULL)
	{
		temp2 = head->next;
		head->next = temp1;
		temp1 = head;
		head = temp2;
		noOfLinks++;
	}
	head = temp1;
	temp1 = NULL;
	minNumberOfNodes = (noOfLinks / 2) + 1;
	while (head != NULL)
	{
		temp2 = head->next;
		head->next = temp1;
		temp1 = head;
		head = temp2;
	}
	head = temp1;
	while (count != minNumberOfNodes)
	{
		temp1 = temp1->next;
		count++;
	}
	temp2 = temp1;
	do
	{
		temp1 = temp1->next;
		loopCount++;
	} while (temp2 != temp1);
	resultIndex = ((noOfLinks - loopCount + 1) / 2) - 1;
	while (resultIndex--)
		head = head->next;
	return head->num;
}


void testInputCases()
{
	int i;
	struct node *head1 = numberToLoopLinkedList(123456789, 5);
	struct node *head2 = numberToLoopLinkedList(123456789, 9);
	struct node *head3 = numberToLoopLinkedList(123456789, 8);
	struct node *head4 = numberToLoopLinkedList(123, 1);
	struct node *head5 = numberToLoopLinkedList(1, 1);
	struct testcases
	{
		struct node *head;
		int result;
	}test[5] = {
			{ head1, 5},
			{ head2, 9 },
			{ head3, 8 },
			{ head4, 1 },
			{ head5, 1 }
	};
	for (i = 0; i<5; i++)
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

struct node * numberToLoopLinkedList(int N, int M)
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