#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
	int num;
	struct node *next;
};
struct node *getNode();
struct node *numberToCircularLinkedList(int N);
int circularLinkedListToNumber(struct node *head);

//Main Algorithm Starts Here

struct node *getResult(struct node *head, int val)
{
	struct node *start = head, *newNode;
	while (head->next != start&&head->next->num < val)
		head = head->next;
	newNode = getNode();
	newNode->num = val;
	newNode->next = head->next;
	head->next = newNode;
	return start;
}


void testInputCases()
{
	int i;
	struct node *head1 = numberToCircularLinkedList(12346789);
	struct node *head2 = numberToCircularLinkedList(24680);
	struct node *head3 = numberToCircularLinkedList(2222468);
	struct node *head4 = numberToCircularLinkedList(2);
	struct testcases
	{
		struct node *head;
		int input;
		int result;
	}test[4] = {
			{ head1, 5, 123456789 },
			{ head2, 6, 246680 },
			{ head3, 2, 22222468 },
			{ head4, 9, 29 }
	};
	for (i = 0; i<4; i++)
	{
		if (circularLinkedListToNumber(getResult(test[i].head, test[i].input)) == test[i].result)
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

struct node * numberToCircularLinkedList(int N)
{
	struct node *start = NULL, *newNode, *end = NULL;
	newNode = getNode();
	newNode->num = N % 10;
	newNode->next = start;
	start = end = newNode;
	N /= 10;
	while (N)
	{
		newNode = getNode();
		newNode->num = N % 10;
		newNode->next = start;
		start = newNode;
		N /= 10;
	}
	end->next = start;
	return start;
}

int circularLinkedListToNumber(struct node *head)
{
	int result = 0;
	struct node *start = head;
	do
	{
		result = (result * 10) + head->num;
		head = head->next;
	} while (head != NULL&&head != start);
	return result;
}