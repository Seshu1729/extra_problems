#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
	int num;
	struct node *next;
};
struct node *getNode();
struct node *numberToLinkedList(int N);
int linkedListToNumber(struct node *head);

//Main Algorithm Starts Here

struct node *getResult(struct node *head)
{
	struct node  *t1 = NULL, *t2 = NULL;
	while (head != NULL)
	{
		t2 = head->next;
		head->next = t1;
		t1 = head;
		head = t2;
	}
	return t1;
}


void testInputCases()
{
	int i;
	struct node *head1 = numberToLinkedList(1234);
	struct node *head2 = numberToLinkedList(12345);
	struct testcases
	{
		struct node *head;
		int result;
	}test[2] = {
			{ head1, 4321 },
			{ head2, 54321 }
	};
	for (i = 0; i<2; i++)
	{
		if (linkedListToNumber(getResult(test[i].head)) == test[i].result)
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

struct node * numberToLinkedList(int N)
{
	struct node *start = NULL, *newNode;
	while (N)
	{
		newNode = getNode();
		newNode->num = N % 10;
		newNode->next = start;
		start = newNode;
		N /= 10;
	}
	return start;
}

int linkedListToNumber(struct node *head)
{
	int result = 0;
	do
	{
		result = (result * 10) + head->num;
		head = head->next;
	} while (head != NULL);
	return result;
}